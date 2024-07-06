// https://geeksforgeeks.org/problems/prerequisite-tasks/1

class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &arr)
    {
        unordered_map<int, list<int>> adj;
        vector<int> indegree(N, 0);
        for (int i = 0; i < P; i++)
        {
            adj[arr[i].second].push_back(arr[i].first);
            indegree[arr[i].first]++;
        }
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty())
        {
            int front = q.front();
            ans.push_back(front);
            q.pop();
            for (auto it : adj[front])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (ans.size() == N)
            return 1;
        return 0;
    }
};