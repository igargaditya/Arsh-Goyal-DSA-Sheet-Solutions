// Leetcode 21
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummynode = new ListNode(-1);
        ListNode *temp = dummynode;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                temp->next = list2;
                list2 = list2->next;
            }
            else
            {
                temp->next = list1;
                list1 = list1->next;
            }
            temp = temp->next;
        }
        while (list1 != NULL)
        {
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }
        while (list2 != NULL)
        {
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }
        return dummynode->next;
    }
};