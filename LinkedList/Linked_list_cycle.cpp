// Leetcode 141

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast)
                fast = fast->next;
            slow = slow->next;
            if (fast != NULL && fast == slow)
                return 1;
        }
        return 0;
    }
};