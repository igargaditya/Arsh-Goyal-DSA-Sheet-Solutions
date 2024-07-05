// Leetcode 526

class Solution
{
public:
    int val(int index, int num, int n, vector<int> visted, int element_inserted)
    {
        if (index % num == 0 || num % index == 0)
        {
            element_inserted++;
            if (element_inserted == n)
                return 1;
        }
        else
            return 0;

        visted[num] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visted[i] == 0)
            {
                ans += val(index + 1, i, n, visted, element_inserted);
            }
        }
        visted[num] = 0;
        return ans;
    }
    int countArrangement(int n)
    {
        int ans = 0;
        vector<int> visted(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            ans += val(1, i, n, visted, 0);
        }
        return ans;
    }
};