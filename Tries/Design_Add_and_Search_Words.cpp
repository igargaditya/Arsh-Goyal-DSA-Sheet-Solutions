// LEETCODE 211

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

class WordDictionary
{
public:
    Node *root;
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->contains(word[i]))
            {
                Node *newnode = new Node();
                temp->links[word[i] - 'a'] = newnode;
                temp = newnode;
            }
            else
            {
                temp = temp->links[word[i] - 'a'];
            }
        }
        temp->flag = 1;
    }

    bool searchh(string word, Node *temp)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (temp->links[j] != NULL)
                    {
                        if (searchh(word.substr(i + 1), temp->links[j]) == 1)
                            return 1;
                    }
                }
                return 0;
            }
            else if (!temp->contains(word[i]))
                return 0;
            else
            {
                temp = temp->links[word[i] - 'a'];
            }
        }
        return temp->flag;
    }
    bool search(string word)
    {
        Node *temp = root;
        return searchh(word, temp);
    }
};
