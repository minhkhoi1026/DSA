#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct DataRes {
	int i;
	int j;
	int type;
};

int* computePrefixFunction(const char* P) {
	int m = strlen(P);
	int* pi = new int[m + 1];
	pi[1] = pi[0] = 0;
	int k = 0;
	for (int q = 2; q <= m; ++q) {
		while (k > 0 && P[k] != P[q - 1])
			k = pi[k];
		if (P[k] == P[q - 1])
			++k;
		pi[q] = k;
	}
	return pi;
}

vector<int> KMPMatcher(char* T, const char* P, int* pi) {
	vector<int> res;
	int n = strlen(T);
	int m = strlen(P);

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
	return res;
}

void readTable(char**& a, int& W, int& H) {
	cin >> W >> H;
	a = new char* [W];
	for (int i = 0; i < W; i++)
		a[i] = new char[H];

	for (int i = 0; i < W; i++)
		for (int j = 0; j < H; j++) {
			getchar();
			cin >> a[i][j];
		}
}

char** rotateTable(char** a, int W, int H) {
	char** a_rotate = new char* [H];
	for (int i = 0; i < H; i++)
		a_rotate[i] = new char[W];
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			a_rotate[i][j] = a[j][i];
		}
	return a_rotate;
}

void deleteTable(char** a, int W, int H) {
	for (int i = 0; i < W; i++)
		delete[] a[i];
	delete[] a;
}

void findWord(const char* word, char** a, int W, int H, vector<DataRes>& res, int type) {
	// pre compute prefix function
	// advoid wasting time to compute same word multiple time.
	int* pi = computePrefixFunction(word);
	// for each row in table, muse KMP to find pattern string in that row text string
	for (int i = 0; i < W; i++) {
		vector<int> tmp = KMPMatcher(a[i], word, pi);
		// push back result of current row to all row result
		for (int j = 0; j < tmp.size(); ++j)
			res.push_back({ i + 1, tmp[j] + 1, type });
	}
	delete pi;
}

void writeResult(string word, vector<DataRes> res) {
	if (res.empty())
		cout << word << " (0, 0) NF\n";
	for (int i = 0; i < res.size(); i++) {
		if (res[i].type == 0)
			cout << word << " (" << res[i].i << ", " << res[i].j << ") LR\n";
		else
			cout << word << " (" << res[i].j << ", " << res[i].i << ") TD\n";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int W, H;
	char** a;
	readTable(a, W, H);
	char** a_rotate = rotateTable(a, W, H);

	vector<DataRes> res;
	string word;
	while (cin >> word) {
		if (word == "#")
			break;
		res.clear();
		// find word from left to right
		findWord(word.c_str(), a, W, H, res, 0);
		// find word from top to bottom
		findWord(word.c_str(), a_rotate, H, W, res, 1);
		writeResult(word, res);
	}
	deleteTable(a, W, H);
	deleteTable(a_rotate, H, W);
	return 0;
}