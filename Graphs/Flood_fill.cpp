// Leetcode 733

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int initialColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<int> delrow{-1, 0, 1, 0};
        vector<int> delcol{0, -1, 0, 1};
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visted(n, vector<int>(m, 0));
        visted[sr][sc] = 1;
        while (!q.empty())
        {
            int topx = q.front().first;
            int topy = q.front().second;
            image[topx][topy] = color;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = topx + delrow[i];
                int y = topy + delcol[i];
                if (x >= 0 && x < n && y >= 0 && y < m && image[x][y] == initialColor &&
                    visted[x][y] == 0)
                {
                    q.push({x, y});
                    visted[x][y] = 1;
                }
            }
        }
        return image;
    }
};