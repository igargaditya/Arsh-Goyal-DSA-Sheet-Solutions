// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

class Solution
{
public:
    Node *segregate(Node *head)
    {

        Node *dnZero = new Node(-1);
        Node *dnOne = new Node(-1);
        Node *dnTwo = new Node(-1);

        Node *zero = dnZero;
        Node *one = dnOne;
        Node *two = dnTwo;

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = temp;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = temp;
            }
            else
            {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        // 0s 1s 2s , 0 and 1 , 0 and 2 , 1 and 2
        // No ones ;
        if (dnOne->next == NULL)
        {
            zero->next = dnTwo->next;
            two->next = NULL;
            return dnZero->next;
        }
        zero->next = dnOne->next;
        one->next = dnTwo->next;
        two->next = NULL;
        return dnZero->next;
    }
};
