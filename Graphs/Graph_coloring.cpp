// M-coloring
// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution
{
public:
    bool isSafe(int node, int color, vector<int> &colors, int m, int n,
                bool graph[101][101])
    {
        for (int i = 0; i < n; i++)
        {
            if (i != node && graph[i][node] == 1 && color == colors[i])
            {
                return 0;
            }
        }
        return 1;
    }
    bool solve(int node, vector<int> &colors, int m, int n,
               bool graph[101][101])
    {
        if (node == n)
            return 1;

        for (int i = 1; i <= m; i++)
        {
            if (isSafe(node, i, colors, m, n, graph))
            {
                colors[node] = i;
                if (solve(node + 1, colors, m, n, graph) == 1)
                    return 1;
                colors[node] = 0;
            }
        }
        return 0;
    }
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> colors(n, 0);
        if (solve(0, colors, m, n, graph) == 1)
            return 1;
        return 0;
    }
};