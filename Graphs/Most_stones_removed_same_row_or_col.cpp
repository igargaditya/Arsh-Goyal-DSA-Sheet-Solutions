// Leetcode 947

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

void findmax(int &maxx, int &maxy, vector<vector<int>> &stones)
{
    for (int i = 0; i < stones.size(); i++)
    {
        if (maxx <= stones[i][0])
        {
            maxx = stones[i][0];
        }
        if (maxy <= stones[i][1])
        {
            maxy = stones[i][1];
        }
    }
}

void unionRowsCols(dis &d, int maxx, int maxy, vector<vector<int>> &stones)
{
    for (int i = 0; i < stones.size(); i++)
    {
        int row = stones[i][0];
        int col = stones[i][1] + maxx + 1;
        d.unionbysize(row, col);
    }
}
void findcompo(dis &d, int maxx, int maxy, int &components)
{
    for (int i = 0; i <= maxx + maxy + 1; i++)
    {
        if (d.parent[i] == i && d.size[i] > 1)
            components++;
    }
}
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int maxx = 0;
        int maxy = 0;

        findmax(maxx, maxy, stones);

        dis d(maxx + maxy + 1);

        unionRowsCols(d, maxx, maxy, stones);

        int components = 0;

        findcompo(d, maxx, maxy, components);

        return stones.size() - components;
    }
};