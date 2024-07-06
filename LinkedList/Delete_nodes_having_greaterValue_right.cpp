// https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

class Solution
{
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    Node *compute(Node *head)
    {
        head = reverse(head);
        Node *dummynode = new Node(-1);
        Node *temp = dummynode;
        temp->next = head;
        temp = head;
        Node *it = head->next;
        while (it != NULL)
        {
            if (it->data >= temp->data)
            {
                temp->next = it;
                temp = it;
            }
            it = it->next;
        }
        temp->next = NULL;
        return reverse(dummynode->next);
    }
};