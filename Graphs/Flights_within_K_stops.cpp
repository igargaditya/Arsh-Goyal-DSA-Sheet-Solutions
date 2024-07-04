// Leetcode 787

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<int, list<pair<int, int>>> adj;
        // from - {to,price}
        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            adj[u].push_back({v, price});
        }
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>,
                       greater<pair<pair<int, int>, int>>>
            pq; // {price , whichnode} , stops
        pq.push({{0, src}, 0});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while (!pq.empty())
        {
            int stops = pq.top().first.first;
            int whichnode = pq.top().first.second;
            int price = pq.top().second;
            if (stops >= k + 1)
                break;

            pq.pop();
            for (auto it : adj[whichnode])
            {
                if (price + it.second < dist[it.first])
                {
                    dist[it.first] = price + it.second;
                    pq.push({{stops + 1, it.first}, dist[it.first]});
                }
            }
        }
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};