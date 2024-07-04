// Leetcode 208

class Node
{
public:
    Node *links[26];
    bool starts = 0;
    bool ends = 0;
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

    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->contains(word[i]))
            {
                temp = temp->links[word[i] - 'a'];
            }
            else
            {
                Node *newnode = new Node();
                temp->links[word[i] - 'a'] = newnode;
                temp = newnode;
                temp->starts = 1;
            }
        }

        temp->ends = 1;
    }

    bool search(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->contains(word[i]))
            {
                temp = temp->links[word[i] - 'a'];
            }
            else
                return 0;
        }
        return temp->ends;
    }

    bool startsWith(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->contains(word[i]))
            {
                temp = temp->links[word[i] - 'a'];
            }
            else
                return 0;
        }
        return temp->starts;
    }
};