class Solution
{
public:
    void find(int x, int y, vector<vector<int>> &m, int n, string temp,
              vector<string> &ans, vector<vector<int>> &visted)
    {
        visted[x][y] = 1;
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(temp);
            visted[x][y] = 0;
            return;
        }
        // Down
        if (x + 1 < n && m[x + 1][y] == 1 && visted[x + 1][y] == 0)
        {
            find(x + 1, y, m, n, temp + 'D', ans, visted);
        }
        // Left
        if (y - 1 >= 0 && m[x][y - 1] == 1 && visted[x][y - 1] == 0)
        {
            find(x, y - 1, m, n, temp + 'L', ans, visted);
        }
        // Right
        if (y + 1 < n && m[x][y + 1] == 1 && visted[x][y + 1] == 0)
        {
            find(x, y + 1, m, n, temp + 'R', ans, visted);
        }
        // Up
        if (x - 1 >= 0 && m[x - 1][y] == 1 && visted[x - 1][y] == 0)
        {
            find(x - 1, y, m, n, temp + 'U', ans, visted);
        }
        visted[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        string temp = "";
        if (m[n - 1][n - 1] == 0 || m[0][0] == 0)
            return ans;
        vector<vector<int>> visted(n, vector<int>(n, 0));
        find(0, 0, m, n, temp, ans, visted);
        return ans;
    }
};