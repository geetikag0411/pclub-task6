#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int t = rand() % 10;
    cout << t << '\n';
    for (int i = 0; i < t; i++)
    {
        int n = rand() % 48 + 2, m = rand() % 48 + 2;
        cout << n << ' ' << m << '\n';
        for (int j = 0; j < n; j++)
            cout << rand() % 49 + 1 << " ";
        cout << '\n';
        for (int j = 0; j < m; j++)
            cout << rand() % 2500 << " ";
        cout << '\n';
    }

    return 0;
}