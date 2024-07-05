// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution
{
public:
    void topo(stack<int> &st, unordered_map<int, list<int>> &adj,
              vector<int> &visted, int node)
    {
        visted[node] = 1;
        for (auto it : adj[node])
        {
            if (visted[it] == 0)
            {
                topo(st, adj, visted, it);
            }
        }
        st.push(node);
    }
    void dfs(int node, vector<int> &visted, vector<vector<int>> &adj)
    {
        visted[node] = 1;
        for (auto it : adj[node])
        {
            if (visted[it] == 0)
            {
                dfs(it, visted, adj);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &adj)
    {

        // Make the reverse of the given graph
        unordered_map<int, list<int>> adjls;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                adjls[adj[i][j]].push_back(i);
            }
        }

        // apply toposort. to find which number of scc as scc will remain connected
        vector<int> visted(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (visted[i] == 0)
                topo(st, adjls, visted, i);
        }

        // Apply Dfs on the toposort to find the scc
        int ans = 0;
        for (int i = 0; i < V; i++)
            visted[i] = 0;
        while (!st.empty())
        {
            if (visted[st.top()] == 0)
            {
                ans++;
                dfs(st.top(), visted, adj);
            }
            st.pop();
        }
        return ans;
    }
};