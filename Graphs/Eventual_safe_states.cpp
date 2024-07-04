//  LeetCode 802

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        unordered_map<int, list<int>> adj;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty())
        {
            int top = q.front();
            ans.push_back(top);
            q.pop();
            for (auto it : adj[top])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};