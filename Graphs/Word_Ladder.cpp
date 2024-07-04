// Leetcode 127

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        set<string> words;
        for (auto it : wordList)
        {
            words.insert(it);
        }
        if (words.find(endWord) == words.end())
            return 0;

        queue<pair<string, int>> q;
        // word level
        q.push({beginWord, 1});
        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                string front = q.front().first;
                int level = q.front().second;
                q.pop();
                for (int a = 0; a < front.size(); a++)
                {
                    string temp = front;
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        temp[a] = j;
                        if (words.find(temp) != words.end())
                        {
                            if (temp == endWord)
                                return level + 1;
                            q.push({temp, level + 1});
                            words.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};