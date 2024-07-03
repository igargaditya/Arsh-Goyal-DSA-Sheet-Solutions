// Leetcode 84

class Solution
{
public:
    void findleft(vector<int> &heights, vector<int> &left, int n)
    {
        stack<pair<int, int>> st;
        st.push({0, heights[0]});
        for (int i = 1; i < n; i++)
        {
            if (!st.empty() && heights[i] > st.top().second)
            {
                left[i] = st.top().first + 1;
                st.push({i, heights[i]});
            }
            else
            {
                while (!st.empty() && heights[i] <= st.top().second)
                {
                    st.pop();
                }
                if (!st.empty())
                    left[i] = st.top().first + 1;

                st.push({i, heights[i]});
            }
        }
    }
    void findright(vector<int> &heights, vector<int> &right, int n)
    {
        stack<pair<int, int>> st;
        st.push({n - 1, heights[n - 1]});
        for (int i = n - 2; i >= 0; i--)
        {
            if (!st.empty() && heights[i] > st.top().second)
            {
                right[i] = st.top().first - 1;
                st.push({i, heights[i]});
            }
            else
            {
                while (!st.empty() && heights[i] <= st.top().second)
                    st.pop();

                if (!st.empty())
                    right[i] = st.top().first - 1;

                st.push({i, heights[i]});
            }
        }
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> leftsmaller(n, 0);
        vector<int> rightsmaller(n, n - 1);

        // make the leftsmaller array
        findleft(heights, leftsmaller, n);
        // make the rightsmaller array
        findright(heights, rightsmaller, n);
        for (auto it : leftsmaller)
            cout << it << " ";
        cout << endl;
        for (auto it : rightsmaller)
            cout << it << " ";
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max((rightsmaller[i] - leftsmaller[i] + 1) * heights[i], ans);
        }
        return ans;
    }
};