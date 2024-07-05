// Leetcode 1290

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        int ans = 0;
        temp = head;
        len--;
        while (temp != NULL)
        {
            ans += temp->val * pow(2, len);
            len--;
            temp = temp->next;
        }
        return ans;
    }
};