#pragma once
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

bool isPrefix(const char* a, const char* b)
{
    int n = strlen(a);
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i])
            return 0;
    return 1;
}

vector<int> bruteForceMatcher(char* T, char* P)
{
    vector<int> res;
    int n = strlen(T);
    int m = strlen(P);

    for (int i = 0; i <= n - m; ++i)
        if (isPrefix(P, T + i))
            res.push_back(i);
    return res;
    
}

//int main()
//{
//    char P[] = "ab";
//    char T[] = "abacdeaaaaba";
//    vector<int> kq = bruteForceMatcher(T, P);
//    for (int i  = 0; i < kq.size(); ++i) 
//        cout << kq[i] << " ";
//    cout << endl;
//}