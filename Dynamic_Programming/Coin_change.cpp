// Leetcode 322

class Solution
{
public:
    int f(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 0;
        if (index == coins.size() - 1)
        {
            if (amount % coins[index] == 0)
                return amount / coins[index];
            else
                return 1e9;
        }
        if (dp[index][amount] != -1)
            return dp[index][amount];

        int pick = 1e9;
        if (amount >= coins[index])
        {
            pick = 1 + f(index, amount - coins[index], coins, dp);
        }
        int notpick = f(index + 1, amount, coins, dp);
        return dp[index][amount] = min(pick, notpick);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int val = f(0, amount, coins, dp);
        if (val >= 1e9)
            return -1;
        return val;
    }
};