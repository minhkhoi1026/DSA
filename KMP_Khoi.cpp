#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

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

vector<int> KMPMatcher(char* T, char* P) {
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

//int main()
//{
//	char P[] = "ab";
//	char T[] = "abacdeaaaaba";
//	vector<int> kq = KMPMatcher(T, P);
//	for (int i = 0; i < kq.size(); ++i)
//		cout << kq[i] << " ";
//	cout << endl;
//}