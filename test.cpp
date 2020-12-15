#include <bits/stdc++.h>

using namespace std;

void generateTest(const string filename, int m, int n, int k, bool log = 0 , int wrongRatio = 2)
{
    char a[m][n];

    fstream fs(filename, fstream::out);
    fs << m << " " << n << endl;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            a[i][j] = rand() % 26 + 'A';
            fs << a[i][j] << " ";
        }
        fs << endl;
    }

    int i, j, l;
    bool state;
    string s;
    while(k--)
    {
        state = rand() % 2;
        if (state) l = rand() % m + 1;
        else       l = rand() % n + 1;

        i = rand() % m;
        j = rand() % n;
        if (state) i = rand() % (m - l + 1);
        else       j = rand() % (n - l + 1);
        if (log) cout << "(" << i + 1 << ", " << j + 1 << "): ";

        s = "";
        while (l--)
        {
            if (state) s += a[i++][j];
            else       s += a[i][j++];
        }
        if (log) cout << s << " -> ";
        
        while (rand() % wrongRatio)
        {
            s[rand() % s.length()] = rand() % 26 + 'A';
        }
        if (log) cout << s << endl;
        fs << s << endl;
    }

    fs << "#";
    fs.close();
}


int main()
{
    srand(time(NULL));

    int m, n, k;
    cin >> m >> n >> k; 
    generateTest("1.txt", m, n, k, 1);
}