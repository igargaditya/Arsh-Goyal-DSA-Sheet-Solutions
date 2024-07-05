// Leetcode 78

class Solution
{
public:
    void f(int index, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        // Take and recursion
        temp.push_back(nums[index]);
        f(index + 1, nums, temp, ans);
        temp.pop_back();

        // Not take and recursion
        f(index + 1, nums, temp, ans);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        // ans.push_back({});
        f(0, nums, temp, ans);
        return ans;
    }
};