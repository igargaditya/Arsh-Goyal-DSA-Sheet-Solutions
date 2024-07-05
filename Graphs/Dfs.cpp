// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution
{
public:
    void dfs(int node, vector<int> &ans, vector<int> adj[],
             vector<int> &visted)
    {
        ans.push_back(node);
        visted[node] = 1;
        for (auto it : adj[node])
        {
            if (visted[it] == 0)
            {
                dfs(it, ans, adj, visted);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> visted(V, 0);
        vector<int> ans;
        dfs(0, ans, adj, visted);
        return ans;
    }
};