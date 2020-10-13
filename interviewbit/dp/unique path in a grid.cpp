#include <bits/stdc++.h>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0)
                if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}
