// Leetcode 1319

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
        if (u == parent[u])
            return u;
        return parent[u] = findparent(parent[u]);
    }
    void unionbysize(int u, int v)
    {
        int up = findparent(u);
        int vp = findparent(v);
        if (up == vp)
            return;
        if (size[vp] > size[up])
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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        dis d(n);
        int extracables = 0;
        for (int i = 0; i < connections.size(); i++)
        {
            int first = connections[i][0];
            int second = connections[i][1];

            if (d.findparent(first) == d.findparent(second))
                extracables++;
            else
                d.unionbysize(first, second);
        }

        int compo = 0;
        for (int i = 0; i < n; i++)
        {
            if (d.parent[i] == i)
                compo++;
        }

        if (compo - 1 <= extracables)
            return compo - 1;
        return -1;
    }
};