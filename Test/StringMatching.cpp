#include <chrono>
#include <ctime>
#include "DataGenerator.h"
#include "StringMatching.h"

long long evalTime(vector<int> (*stringMatchFunc)(char*, char*), char* P, char* T) {
	auto startTime = std::chrono::high_resolution_clock::now();
	(*stringMatchFunc)(P, T);
	auto endTime = std::chrono::high_resolution_clock::now();
	auto durationTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	return (double)durationTime.count();
}

long long stringMatchTime(char* P, char* T, int funcType) {
	switch (funcType) {
	case 1:
		return evalTime(bruteForceMatcher, P, T);
		break;
	case 2:
		return evalTime(rabinKarpMatcher, P, T);
		break;
	case 3:
		return evalTime(KMPMatcher, P, T);
		break;
	}
	return -1;
}

bool isPrefix(const char* a, const char* b)
{
	int n = strlen(a);
	for (int i = 0; i < n; ++i)
		if (a[i] != b[i])
			return 0;
	return 1;
}

vector<int> bruteForceMatcher(char* P, char* T)
{
	vector<int> res;
	int n = strlen(T);
	int m = strlen(P);

	for (int i = 0; i <= n - m; ++i)
		if (isPrefix(P, T + i))
			res.push_back(i);
	return res;

}


vector<int> rabinKarpMatcher(char* P, char* T) {
	// choose base = p and mod = m
	const int p = 31;
	const int MOD = 1e9 + 9;

	// length of patter and text
	int n = strlen(T), m = strlen(P);

	// pre-compute exponent of i with base p
	vector<long long> p_pow(n);
	p_pow[0] = 1;
	for (int i = 1; i < p_pow.size(); ++i)
		p_pow[i] = (p_pow[i - 1] * p) % MOD;

	// pre-compute hash of every prefix of text string
	vector<long long> h(n + 1, 0);
	for (int i = 0; i < n; i++)
		h[i + 1] = (h[i] + (long long)(T[i] - 'a' + 1) * p_pow[i] % MOD) % MOD;

	// pre-compute hash of pattern string
	long long h_s = 0;
	for (int i = 0; i < m; i++)
		h_s = (h_s + (long long)(P[i] - 'a' + 1) * p_pow[i] % MOD) % MOD;

	// start matching
	vector<int> occurences;
	for (int i = 0; i + m - 1 < n; i++) {
		// current hash of T[i..i + m - 1]
		long long cur_h = (h[i + m] + MOD - h[i]) % MOD;
		// if match then push back i to result
		if (cur_h == h_s * p_pow[i] % MOD)
			occurences.push_back(i);
	}
	return occurences;
}

int* computePrefixFunction(char* P) {
	int m = strlen(P);
	int* pi = new int[m + 1];
	pi[1] = pi[0] = 0;
	int k = 0;
	for (int q = 2; q <= m; ++q) {
		while (k > 0 && P[k] != P[q - 1])
			q = pi[q];
		if (P[k] == P[q - 1])
			++k;
		pi[q] = k;
	}
	return pi;
}

vector<int> KMPMatcher(char* P, char* T) {
	vector<int> res;
	int n = strlen(T);
	int m = strlen(P);

	// compute prefix function pi[q]
	int* pi = computePrefixFunction(P);

	//maching using idea of finite automaton
	int q = 0;
	for (int i = 1; i <= n; i++) {
		while (q > 0 && P[q] != T[i - 1]) // next character does not match
			q = pi[q];
		if (P[q] == T[i - 1]) // next character does match
			++q;
		// current state is m mean the pattern string
		// is completely match with text string
		if (q == m) {
			res.push_back(i - m);
			q = pi[q];
		}
	}
	delete pi;
	return res;
}