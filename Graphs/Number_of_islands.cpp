// Leetcode 200

class Solution
{
public:
    void dfs(int row, int col, vector<int> &delrow, vector<int> &delcol, vector<vector<int>> &visted,
             vector<vector<char>> &grid, int n, int m)
    {
        visted[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int x = row + delrow[i];
            int y = col + delcol[i];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && visted[x][y] == 0)
            {
                dfs(x, y, delrow, delcol, visted, grid, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> delrow{-1, 0, 1, 0};
        vector<int> delcol{0, 1, 0, -1};
        int ans = 0;
        vector<vector<int>> visted(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && visted[i][j] == 0)
                {
                    ans++;
                    dfs(i, j, delrow, delcol, visted, grid, n, m);
                }
            }
        }
        return ans;
    }
};