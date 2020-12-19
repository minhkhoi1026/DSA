#include <bits/stdc++.h>

using namespace std;

bool cmp(const char* a, const char* b, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

vector<int> stringMatching(string T, string P)
{
    vector<int> kq;
    int n = T.length();
    int m = P.length();

    for (int i = 0; i <= n - m; ++i)
    {
        if (cmp(T.c_str() + i, P.c_str(), m))
            kq.push_back(i);
    }
    return kq;
    
}

int main()
{
    string a = "ab";
    string b = "abcdeab";
    vector<int> kq = stringMatching(b, a);
    for (int i  = 0; i < kq.size(); ++i) cout << kq[i] << " ";
    cout << endl;
}