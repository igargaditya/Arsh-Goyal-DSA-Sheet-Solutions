// Leetcode 160

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        if (temp1 == temp2)
            return temp1;
        bool first = 0;
        bool second = 0;
        while (temp1 != NULL && temp2 != NULL)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
            if (temp1 == NULL && first == 0)
            {
                temp1 = headB;
                first = 1;
            }
            if (temp2 == NULL && second == 0)
            {
                temp2 = headA;
                second = 1;
            }
            if (temp1 == temp2)
                return temp1;
        }
        return NULL;
    }
};