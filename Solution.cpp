#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int coin[n], jewell[m];
        for (int i = 0; i < n; i++)
        {
            cin >> coin[i];
        }
        int max_price = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> jewell[i];
            max_price = max(max_price, jewell[i]);
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(max_price + 1));
        for (int j = 1; j <= max_price; j++)
            dp[0][j] = false;
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= max_price; j++)
            {

                if (dp[i - 1][j] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    int val = coin[i - 1];
                    if (j >= val && dp[i - 1][j - val] == true)
                    {
                        dp[i][j] = true;
                    }
                }
            }
        }
        int iMin = 0, a[m];
        while (!dp[n][jewell[iMin]])
        {
            a[iMin] = -1;
            iMin++;
        }
        for (int i = iMin; i < m; i++)
        {
            if (dp[n][jewell[i]] && jewell[i] < jewell[iMin])
                iMin = i;
            a[i] = iMin;
        }
        int ans = 0;
        for (int i = 1; i < m; i++)
        {
            if (a[i] != -1)
                ans = max(jewell[i] - jewell[a[i]], ans);
        }
        cout << ans << '\n';
    }
}
