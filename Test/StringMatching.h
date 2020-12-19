#pragma once
#include <vector>


vector<int> bruteForceMatcher(char* P, char* T);
vector<int> rabinKarpMatcher(char* P, char* T);
vector<int> KMPMatcher(char* P, char* T);
long long stringMatchTime(char* P, char* T, int funcType);
