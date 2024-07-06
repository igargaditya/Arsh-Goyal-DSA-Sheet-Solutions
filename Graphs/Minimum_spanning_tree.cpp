// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // wt node
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<int> visted(V, 0);
        // visted[0]=1 ;
        int ans = 0;
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (visted[node] == 1)
                continue;
            ans += wt;
            visted[node] = 1;

            for (auto it : adj[node])
            {
                int dist = it[1];
                int neigh = it[0];
                if (visted[neigh] == 0)
                {
                    pq.push({dist, neigh});
                }
            }
        }
        return ans;
    }
};
