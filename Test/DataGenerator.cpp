#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <string>
using namespace std;



void GenerateRandomData(char* substr, char* str, int m,int n) {
	for (int i = 0; i < m; ++i) {
		substr[i] = rand() % 26 + 'a';
	}
	substr[m] = '\0';
	for (int i = 0; i < n; ++i) {
		str[i] = rand() % 26 + 'a';
	}
	str[n] = '\0';

}

void NotOccursData(char* substr, char* str,int m,int n) {
	substr[0] = rand() % 26 + 'a';
	for (int i = 1; i < m; ++i) {
		substr[i] = rand() % 26 + 'a';
	}
	substr[m] = '\0';
	for (int i = 0; i < n; ++i) {
		do {
			str[i] = rand() % 26 + 'a';
		} while (str[i] == substr[0]);
	}
	str[n] = '\0';
}

void OccursManyData(char* substr, char* str,int m, int n) {
	for (int i = 0; i < m; ++i) {
		substr[i] = rand() % 26 + 'a';
	}
	substr[m] = '\0';
	int j = 0;
	for (int i = 0; i < n; ++i) {
		str[i] = substr[j++];
		if (j == m)
			j = 0;
	}
	str[n] = '\0';
}

void GenerateData(char* substr, char* str,int m,int n, int dataType) {
	switch (dataType) {
	case 0:
		GenerateRandomData(substr, str,m,n);
		break;
	case 1:
		NotOccursData(substr, str,m,n);
		break;
	case 2:
		OccursManyData(substr, str,m,n);
		break;
	}
}

