#include <bits/stdc++.h>

using namespace std;

void generateTest(const string filename, int m, int n, int k)
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
    for (int t = 0; t < k; ++t)
    {
        i = rand() % m;
        j = rand() % n;
        fs << "(" << i + 1 << ", " << j + 1 << "): ";

        s = "";
        state = rand() % 2;
        if (state) l = rand() % (m - i) + 1;
        else       l = rand() % (n - j) + 1;
        while (l--)
        {
            if (state) s += a[i++][j];
            else       s += a[i][j++];
        }

        //if (rand() % 2)
        //    s[0] = s[1];

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
    generateTest("1.txt", m, n, k);
}