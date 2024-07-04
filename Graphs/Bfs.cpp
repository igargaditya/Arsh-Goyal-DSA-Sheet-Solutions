class Solution
{
public:
    int f(int start, int end, int extra, vector<pair<int, int>> &freq,
          vector<vector<vector<int>>> &dp)
    {
        if (start > end)
            return 0;

        if (dp[start][end][extra] != -1)
            return dp[start][end][extra];

        int ans = (extra + freq[start].first) * (extra + freq[start].first) + f(start + 1, end, 0, freq, dp);
        for (int i = start + 1; i <= end; i++)
        {
            if (freq[i].second == freq[start].second)
            {
                ans = max(ans, f(start + 1, i - 1, 0, freq, dp) + f(i, end, extra + freq[start].first, freq, dp));
            }
        }
        return dp[start][end][extra] = ans;
    }
    int removeBoxes(vector<int> &boxes)
    {

        vector<pair<int, int>> freq;
        int temp = 1;
        vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, -1)));
        if (boxes.size() == 1)
        {
            freq.push_back({1, boxes[0]});
        }
        else
        {
            for (int i = 0; i < boxes.size() - 1; i++)
            {
                if (boxes[i] == boxes[i + 1])
                {
                    temp++;
                }
                else
                {
                    freq.push_back({temp, boxes[i]});
                    temp = 1;
                }
                if (i == boxes.size() - 2)
                    freq.push_back({temp, boxes[i + 1]});
            }
        }

        int n = freq.size();

        f(0, n - 1, 0, freq, dp);
        return dp[0][n - 1][0];
    }
};