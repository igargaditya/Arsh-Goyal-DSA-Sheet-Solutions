// Leetcode 684

class dis
{
public:
    vector<int> parent;
    vector<int> size;
    dis(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findparent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findparent(parent[u]);
    }
    void unionbysize(int u, int v)
    {
        int up = findparent(u);
        int vp = findparent(v);
        if (up == vp)
            return;
        if (size[up] > size[vp])
        {
            parent[vp] = up;
            size[up] += size[vp];
        }
        else
        {
            parent[up] = vp;
            size[vp] += size[up];
        }
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        dis d(n);
        vector<int> ans;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if (d.findparent(u) == d.findparent(v))
                ans = {u, v};
            else
                d.unionbysize(u, v);
        }
        return ans;
    }
};