#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string>
using namespace std;



void GenerateRandomData(string substr, string str, int n) {
	int m = rand() % n;
	for (int i = 0; i < m; ++i) {
		substr[i] = rand() % 26 + 'a';
	}
	for (int i = 0; i < n; ++i) {
		str[i] = rand() % 26 + 'a';
	}

}

void NotOccursData(string substr, string str,int n) {
	int m = rand() % n;
	substr[0] = rand() % 26 + 'a';
	for (int i = 1; i < m; ++i) {
		substr[i] = rand() % 26 + 'a';
	}
	for (int i = 0; i < n; ++i) {
		do {
			str[i] = rand() % 26 + 'a';
		} while (str[i] == substr[0]);
	}
}

void OccursManyData(string substr, string str, int n) {
	int m = n / rand();
	for (int i = 0; i < m; ++i) {
		substr[i] = rand() % 26 + 'a';
	}
	int j = 0;
	for (int i = 0; i < n; ++i) {
		str[i] = substr[j++];
		if (j == m)
			j = 0;
	}

}

void GenerateData(string substr, string str,int n, int dataType) {
	switch (dataType) {
	case 0:
		GenerateRandomData(substr, str,n);
		break;
	case 1:
		NotOccursData(substr, str,n);
		break;
	case 2:
		OccursManyData(substr, str,n);
		break;
	}
}

