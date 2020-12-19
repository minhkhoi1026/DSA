#include "DataGenerator.h"
#include "StringMatching.h"
#include <fstream>

using namespace std;

int main() {
	ofstream fout("DataStringMatching.csv", ios::out);
	if (!fout) {
		cout << " Khong tao duoc file \n";
		exit(0);
	}
	int size[] = { 3000, 10000, 30000, 100000, 300000 };
	char* substr;
	char* str;
	fout << "Data Type,Size,Brute Force, Rabin Karp, KMP\n";
	for (int i = 0; i <= 2; ++i) {
		for (int j = 0; j < 5; ++j) {
			fout << i << "," << size[j] << ",";
			for (int k = 2; k <= 2; ++k) {
				str = new char[size[j] + 2];
				int sSize;
				if (i == 1 || i == 2) {
					continue;
				}
				else {
					sSize = size[j] / rand();
				}
				substr = new char[sSize + 2];
				GenerateData(substr, str, sSize, size[j],i);
				cout << stringMatchTime(substr, str, k) <<",";
				delete[] substr;
				delete[] str;
			}
			fout << "\n";
		}
	}
	fout.close();
	return 0;
}