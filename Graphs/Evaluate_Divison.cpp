// Leetcode 399

class Solution
{
public:
    unordered_map<string, list<pair<string, double>>> adj;
    double bfs(string a, string b)
    {
        if (adj.find(a) == adj.end() or adj.find(b) == adj.end())
            return -1;

        unordered_map<string, int> visited;
        queue<pair<string, double>> q;
        q.push({a, 1.0});
        while (!q.empty())
        {
            string curr = q.front().first;
            visited[curr] = 1;
            double currWeight = q.front().second;
            q.pop();
            if (curr == b)
                return currWeight;

            for (auto neighbour : adj[curr])
            {
                if (visited[neighbour.first] == 0)
                {
                    q.push({neighbour.first, (double)neighbour.second * currWeight});
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        for (int i = 0; i < equations.size(); i++)
        {
            string first = equations[i][0];
            string second = equations[i][1];
            adj[first].push_back({second, values[i]});
            adj[second].push_back({first, 1 / (1.0 * values[i])});
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(bfs(queries[i][0], queries[i][1]));
        }
        return ans;
    }
};