// Leetcode 131

class Solution
{
public:
    bool ispalindrome(string s)
    {
        int st = 0;
        int end = s.size() - 1;
        while (st <= end)
        {
            if (s[st] != s[end])
                return 0;
            st++;
            end--;
        }
        return 1;
    }
    void f(int index, string s, vector<string> &temp, vector<vector<string>> &ans)
    {
        if (index == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {

            if (ispalindrome(s.substr(index, i - index + 1)))
            {
                temp.push_back(s.substr(index, i - index + 1));
                f(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {

        vector<vector<string>> ans;
        vector<string> temp;
        f(0, s, temp, ans);
        return ans;
    }
};