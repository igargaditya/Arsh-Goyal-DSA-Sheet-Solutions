class Solution
{
public:
    void bfs(queue<pair<int, int>> &pq, vector<vector<int>> &grid,
             vector<vector<int>> &visted, int n)
    {
        vector<int> delrow{-1, 0, 1, 0};
        vector<int> delcol{0, 1, 0, -1};
        while (!pq.empty())
        {
            int x = pq.front().first;
            int y = pq.front().second;
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = x + delrow[i];
                int yy = y + delcol[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && grid[xx][yy] == 1 && visted[xx][yy] == 0)
                {
                    pq.push({xx, yy});
                    visted[xx][yy] = 1;
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> visted(n, vector<int>(n, 0));
        queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            bool temp = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    pq.push({i, j});
                    visted[i][j] = 1;
                    temp = 1;
                    break;
                }
            }
            if (temp)
                break;
        }

        bfs(pq, grid, visted, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visted[i][j] == 1)
                    pq.push({i, j});
            }
        }
        int level = 0;
        vector<int> delrow{-1, 0, 1, 0};
        vector<int> delcol{0, 1, 0, -1};
        while (!pq.empty())
        {
            int size = pq.size();
            for (int i = 0; i < size; i++)
            {
                int x = pq.front().first;
                int y = pq.front().second;
                pq.pop();
                for (int j = 0; j < 4; j++)
                {
                    int xx = x + delrow[j];
                    int yy = y + delcol[j];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < n && grid[xx][yy] == 1 && visted[xx][yy] == 0)
                        return level;
                    if (xx >= 0 && xx < n && yy >= 0 && yy < n && visted[xx][yy] == 0)
                    {
                        pq.push({xx, yy});
                        visted[xx][yy] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};