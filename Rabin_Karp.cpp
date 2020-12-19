#pragma once
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> RabinKarpMatcher(char* T,char* P) {
	// choose base = p and mod = m
	const long long p = 31;
	const long long MOD = 1e9 + 9;

	// length of patter and text
	int n = strlen(T), m = strlen(P);

	// pre-compute exponent of i with base p
	vector<long long> p_pow(n);
	p_pow[0] = 1;
	for (int i = 1; i < p_pow.size(); ++i)
		p_pow[i] = (p_pow[i - 1] * p) % MOD;

	// pre-compute hash of every prefix of text string
	vector<long long> h(n + 1, 0);
	for (int i = 0; i < n; ++i)
		h[i + 1] = (h[i] + (long long)(T[i] - 'a' + 1) * p_pow[i] % MOD) % MOD;

	// pre-compute hash of pattern string
	long long h_s = 0;
	for (int i = 0; i < m; ++i)
		h_s = (h_s + (long long)(P[i] - 'a' + 1) * p_pow[i] % MOD) % MOD;

	// start matching
	vector<int> occurences;
	for (int i = 0; i + m - 1 < n; ++i) {
		// current hash of T[i..i + m - 1]
		long long cur_h = (h[i + m] + MOD - h[i]) % MOD;
		// if match then push back i to result
		if (cur_h == h_s * p_pow[i] % MOD)
			occurences.push_back(i);
	}
	return occurences;
}

//int main()
//{
//	char P[] = "ab";
//	char T[] = "abacdeaaaaba";
//	vector<int> kq = RabinKarpMatcher(T, P);
//	for (int i = 0; i < kq.size(); ++i)
//		cout << kq[i] << " ";
//	cout << endl;
//}