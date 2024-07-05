// Leetcode 62

class Solution
{
public:
    int f(int row, int col, int m, int n, vector<vector<int>> &dp)
    {
        if (row == m - 1 && col == n - 1)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];
        int right = 0;
        if (col + 1 < n)
        {
            right = f(row, col + 1, m, n, dp);
        }
        int down = 0;
        if (row + 1 < m)
        {
            down = f(row + 1, col, m, n, dp);
        }
        return dp[row][col] = right + down;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f(0, 0, m, n, dp);
    }
};