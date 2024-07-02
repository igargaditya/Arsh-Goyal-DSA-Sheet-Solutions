// Leetcode 935

class Solution
{
public:
    int mod = 1e9 + 7;
    vector<int> delrow{-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> delcol{-1, -2, -2, -1, 1, 2, 2, 1};
    int f(int n, int i, int j, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (n == 1)
            return 1;
        if (dp[i][j][n] != -1)
            return dp[i][j][n];
        long long ans = 0;
        for (int a = 0; a < 8; a++)
        {
            int x = i + delrow[a];
            int y = j + delcol[a];

            if (x >= 0 && x < 4 && y >= 0 && y < 3 && grid[x][y] != -1)
            {
                ans += f(n - 1, x, y, grid, dp) % mod;
            }
        }
        return dp[i][j][n] = (ans % mod);
    }
    int knightDialer(int n)
    {
        vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        long long ans = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] != -1)
                {
                    ans += f(n, i, j, grid, dp) % mod;
                }
            }
        }
        return ans % mod;
    }
};