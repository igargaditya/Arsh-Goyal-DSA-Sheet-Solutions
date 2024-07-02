// LEETCODE 139

class Node
{
public:
    Node *links[26];
    bool flag = 0;
    bool contains(char ch)
    {
        if (links[ch - 'a'])
            return 1;
        return 0;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string s)
    {
        Node *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->contains(s[i]))
            {
                Node *newnode = new Node();
                temp->links[s[i] - 'a'] = newnode;
                temp = newnode;
            }
            else
                temp = temp->links[s[i] - 'a'];
        }
        temp->flag = 1;
    }
    bool check(string s, int index, vector<int> &dp)
    {
        Node *temp = root;
        if (index == s.size())
            return 1;
        if (dp[index] != -1)
            return dp[index];
        for (int i = index; i < s.size(); i++)
        {
            if (temp->contains(s[i]))
            {
                temp = temp->links[s[i] - 'a'];
                if (temp->flag)
                {
                    if (check(s, i + 1, dp) == 1)
                        return dp[i] = 1;
                }
            }
            else
                return dp[i] = 0;
        }
        return dp[index] = temp->flag;
    }
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        Trie t;
        for (auto it : wordDict)
        {
            t.insert(it);
        }
        vector<int> dp(s.size(), -1);

        return t.check(s, 0, dp);
    }
};