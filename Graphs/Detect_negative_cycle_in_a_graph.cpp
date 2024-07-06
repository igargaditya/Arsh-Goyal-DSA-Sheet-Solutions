// https://www.naukri.com/code360/problems/bellmon-ford_2041977?leftPanelTabValue=PROBLEM
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{

    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] + wt < dist[v])
                dist[v] = wt + dist[u];
        }
    }
    return dist;
}
