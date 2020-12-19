#include <bits/stdc++.h>

using namespace std;

struct KQ
{
    string s;
    int x, y, type;
};

int main()
{
    fstream f1("1.txt", fstream::in);
    int m, n;
    f1 >> m >> n;

    char a[m][n];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            f1 >> a[i][j];
        }
    }

    string s;
    KQ tmp;
    vector<KQ> kq;
    int count = 0;
    while(1)
    {
        f1 >> s;
        if (s == "#") break;

        int _count = 0;
        int l = s.length();
        int t;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n - l + 1; ++j)
            {
                for (t = 0; t < l; ++t)
                    if (a[i][j + t] != s[t]) break;

                if (t == l)
                {
                    tmp.s = s; tmp.type = 1;
                    tmp.x = i; tmp.y = j;

                    kq.push_back(tmp);
                    _count++;
                }
            }

        for (int i = 0; i < m - l + 1; ++i)
            for (int j = 0; j < n; ++j)
            {
                bool flag = 1;
                for (t = 0; t < l;  ++t)
                    if (a[i + t][j] != s[t]) break;

                if (t == l)
                {
                    tmp.s = s; tmp.type = 2;
                    tmp.x = i; tmp.y = j;

                    kq.push_back(tmp);
                    _count++;
                }
            }

        if (!_count)
        {
            tmp.s = s; tmp.type = 0;
            tmp.x = -1; tmp.y = -1;

            kq.push_back(tmp);
        }
        count += _count;
    }

    cout << count << endl;
    for (int i = 0; i < kq.size(); ++i)
    {
        cout << kq[i].s << " (" << kq[i].x + 1 << ", " << kq[i].y + 1 << ") ";
        switch (kq[i].type)
        {
        case 0:
            cout << "NF" << endl;
            break;
        case 1:
            cout << "LR" << endl;
            break;
        case 2:
            cout << "TD" << endl;
            break;
        }
    }
    
    f1.close();
}