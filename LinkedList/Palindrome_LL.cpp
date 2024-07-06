// Leetcode 234

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL)
                fast = fast->next;
            slow = slow->next;
        }

        ListNode *reverseHead = reverse(slow->next);
        ListNode *temp1 = head;
        ListNode *temp2 = reverseHead;
        while (temp2 != NULL)
        {
            if (temp1->val != temp2->val)
                return 0;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return 1;
    }
};
