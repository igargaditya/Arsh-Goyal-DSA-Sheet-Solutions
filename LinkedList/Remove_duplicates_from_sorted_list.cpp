// Leetcode 83

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *temp = head;
        ListNode *next = head->next;
        while (next != NULL)
        {
            if (temp->val != next->val)
            {
                temp->next = next;
                temp = next;
            }
            next = next->next;
        }
        temp->next = NULL;

        return head;
    }
};