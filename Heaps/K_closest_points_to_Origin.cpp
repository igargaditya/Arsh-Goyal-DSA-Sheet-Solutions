// Leetcode 973

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < points.size(); i++)
        {
            int distx = points[i][0] * points[i][0];
            int disty = points[i][1] * points[i][1];
            pq.push({distx + disty, {points[i][0], points[i][1]}});
        }
        vector<vector<int>> ans;
        while (k--)
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};