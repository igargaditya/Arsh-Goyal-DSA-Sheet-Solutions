// Leetcode 130

class Solution
{
public:
    void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &visted,
             vector<vector<char>> &board, int n, int m)
    {
        vector<int> delrow{-1, 0, 1, 0};
        vector<int> delcol{0, -1, 0, 1};

        while (!q.empty())
        {
            int topx = q.front().first;
            int topy = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = topx + delrow[i];
                int y = topy + delcol[i];
                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O' && visted[x][y] == false)
                {
                    q.push({x, y});
                    visted[x][y] = true;
                }
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visted(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O' && visted[0][j] == false)
            {
                q.push({0, j});
                visted[0][j] = true;
            }
            if (board[n - 1][j] == 'O' && visted[n - 1][j] == false)
            {
                q.push({n - 1, j});
                visted[n - 1][j] = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O' && visted[i][0] == false)
            {
                q.push({i, 0});
                visted[i][0] = true;
            }
            if (board[i][m - 1] == 'O' && visted[i][m - 1] == false)
            {
                q.push({i, m - 1});
                visted[i][m - 1] = true;
            }
        }

        bfs(q, visted, board, n, m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && visted[i][j] == false)
                    board[i][j] = 'X';
            }
        }
    }
};