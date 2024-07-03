// LeetCode 200

class Solution
{
public:
    void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visted,
             vector<int> delrow, vector<int> delcol, int n, int m)
    {
        visted[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int adjx = x + delrow[i];
            int adjy = y + delcol[i];
            if (adjx >= 0 && adjx < n && adjy >= 0 && adjy < m &&
                grid[adjx][adjy] == '1' && visted[adjx][adjy] == false)
            {
                dfs(adjx, adjy, grid, visted, delrow, delcol, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> delrow{-1, 0, 1, 0};
        vector<int> delcol{0, 1, 0, -1};
        vector<vector<bool>> visted(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && visted[i][j] == false)
                {
                    ans++;
                    dfs(i, j, grid, visted, delrow, delcol, n, m);
                }
            }
        }
        return ans;
    }
};