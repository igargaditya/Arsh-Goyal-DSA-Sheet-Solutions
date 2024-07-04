// Leetcode 1162

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> visted(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    visted[i][j] = 1;
                }
            }
        }
        vector<int> delrow{-1, 0, 1, 0};
        vector<int> delcol{0, 1, 0, -1};
        int level = 1;
        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {

                int frontx = q.front().first;
                int fronty = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int xx = frontx + delrow[j];
                    int yy = fronty + delcol[j];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < n && grid[xx][yy] == 0 && visted[xx][yy] == 0)
                    {
                        visted[xx][yy] = 0;
                        grid[xx][yy] = level;
                        q.push({xx, yy});
                    }
                }
            }
            level++;
        }
        if (level == 2)
            return -1;
        return level - 2;
    }
};