// Leetcode 740
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> arr;
        unordered_map<int, int> mp;
        for (auto it : nums)
            mp[it]++;

        for (auto it : mp)
        {
            arr.push_back(it.first);
        }
        sort(arr.begin(), arr.end());
        if (arr.size() == 1)
            return arr[0] * mp[arr[0]];
        int earn2 = arr[0] * mp[arr[0]];
        int earn1 = arr[1] * mp[arr[1]];
        if (arr[1] != arr[0] + 1)
            earn1 += earn2;

        earn1 = max(earn1, earn2);

        for (int i = 2; i < arr.size(); i++)
        {
            int newvalue = arr[i] * mp[arr[i]];
            if (arr[i] != arr[i - 1] + 1)
                newvalue += earn1;
            else
                newvalue += earn2;

            earn2 = earn1;
            earn1 = max(newvalue, earn1);
        }
        return earn1;
    }
};