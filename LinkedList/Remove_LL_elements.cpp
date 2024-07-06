// Leetcode 203

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *curr = head;
        ListNode *next;
        while (curr != NULL && curr->val == val)
        {
            head = head->next;
            curr = head;
        }
        if (curr != NULL)
            next = curr->next;
        else
            return NULL;
        while (next != NULL)
        {
            if (next->val == val)
                curr->next = next->next;
            else
                curr = next;
            next = next->next;
        }
        return head;
    }
};