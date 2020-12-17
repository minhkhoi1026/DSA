#include <bits/stdc++.h>

using namespace std;

void generateTest(const string filename, int m, int n, int k, bool log = 0 , int minLength = 1, int wrongRatio = 2)
{
    char a[m][n];

    fstream fs(filename, fstream::out);
    fs << m << " " << n << endl;

    // Radom table
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
        i = rand() % m;
        j = rand() % n;

        if(rand() % 2)  //Random position
        {
            if (state) l = rand() % (m - i) + 1;
            else       l = rand() % (n - j) + 1;
        }
        else //Random length
        {
            if (state) l = rand() % m + 1;
            else       l = rand() % n + 1;

            if (state) i = rand() % (m - l + 1);
            else       j = rand() % (n - l + 1);
        }
        if (l < minLength)
        {
            k++;
            continue;
        }

        if (log) cout << "(" << i + 1 << ", " << j + 1 << "): ";

        s = "";
        while (l--)
        {
            if (state) s += a[i++][j];
            else       s += a[i][j++];
        }
        if (log) cout << s;
        
        // Random wrong answer
        bool flag = 0;
        while (rand() % wrongRatio)
        {
            flag = 1;
            s[rand() % s.length()] = rand() % 26 + 'A';
        }

        if (log)
        {
            if (flag) cout << "\t-> " << s;
            cout << endl;
        } 
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
    generateTest("1.txt", m, n, k, 1, 5);
}