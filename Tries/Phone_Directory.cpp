// https://www.geeksforgeeks.org/problems/phone-directory4628/1

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
            if (temp->contains(s[i]))
            {
                temp = temp->links[s[i] - 'a'];
            }
            else
            {
                Node *newnode = new Node();
                temp->links[s[i] - 'a'] = newnode;
                temp = newnode;
            }
        }
        temp->flag = 1;
    }
    void forthat(Node *temp, vector<string> &possible, string ourCurrString)
    {
        if (temp->flag == 1)
        {
            possible.push_back(ourCurrString);
        }
        for (int i = 0; i < 26; i++)
        {
            if (temp->links[i])
            {
                ourCurrString.push_back(i + 'a');
                forthat(temp->links[i], possible, ourCurrString);
                ourCurrString.pop_back();
            }
        }
    }
    void display(string s, vector<vector<string>> &ans)
    {

        Node *temp = root;
        string founded_string = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (temp->contains(s[i]) == 0)
            {
                for (int j = 0; j < s.size() - i; j++)
                {
                    vector<string> notfound = {"0"};
                    ans.push_back(notfound);
                }
                return;
            }
            else
            {
                founded_string += s[i];
                vector<string> possibleAns;
                temp = temp->links[s[i] - 'a'];
                forthat(temp, possibleAns, founded_string);
                ans.push_back(possibleAns);
            }
        }
    }
};
class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie t;
        for (int i = 0; i < n; i++)
        {
            t.insert(contact[i]);
        }
        vector<vector<string>> ans;
        t.display(s, ans);
        return ans;
    }
};