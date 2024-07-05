// Leetcode 980

class Solution
{
public:
    vector<int> delrow{-1, 0, 1, 0};
    vector<int> delcol{0, -1, 0, 1};
    int f(int x, int y, vector<vector<int>> &visted, vector<vector<int>> &grid, int maxWalk, int walked, int n, int m)
    {
        if (grid[x][y] == 2 && maxWalk == walked)
            return 1;
        else if (grid[x][y] == 2 && maxWalk != walked)
            return 0;
        // cout << x << " " << y << endl ;
        visted[x][y] = 1;
        int paths = 0;
        for (int i = 0; i < 4; i++)
        {
            int frontx = x + delrow[i];
            int fronty = y + delcol[i];
            if (frontx >= 0 && fronty >= 0 && frontx < n && fronty < m && grid[frontx][fronty] != -1 && visted[frontx][fronty] == 0)
            {
                walked++;
                paths += f(frontx, fronty, visted, grid, maxWalk, walked, n, m);
                walked--;
            }
        }
        visted[x][y] = 0;
        return paths;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int walkable = 0;
        int n = grid.size();
        int m = grid[0].size();
        int inix = -1;
        int iniy = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != -1)
                    walkable++;
                if (grid[i][j] == 1)
                {
                    inix = i;
                    iniy = j;
                }
            }
        }
        vector<vector<int>> visted(n, vector<int>(m, 0));
        return f(inix, iniy, visted, grid, walkable, 1, n, m);
    }
};