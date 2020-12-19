#include <bits/stdc++.h>

using namespace std;

vector<int> stringMatching(string T, string P)
{
    vector<int> result;
    int n = T.length();
    int m = P.length();
    bool check;

    for (int s = 0; s <= n - m; ++s)
    {
        check = 1;
        for (int j = 0; j < m; ++j)
            if (P[j] != T[s + j])
            {
                check = 0;
                break;
            }
        if (check) result.push_back(s);
    }   
    return result;
}

int main()
{
    string a = "abcdeab";
    string b = "ab";
    vector<int> kq = stringMatching(a, b);
    for (int i  = 0; i < kq.size(); ++i) cout << kq[i] << " ";
    cout << endl;
}