// Leetcode 300
class Solution
{
public:
    int position(int ele, vector<int> &temp)
    {
        int low = 0;
        int high = temp.size() - 1;
        int ans = 0;
        while (low <= high)
        {
            int mid = (low) + (high - low) / 2;
            if (temp[mid] >= ele)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int pos = position(nums[i], temp);
                temp[pos] = nums[i];
            }
        }

        return temp.size();
    }
};