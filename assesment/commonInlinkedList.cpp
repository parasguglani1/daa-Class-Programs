#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node *result = new Node(0);
    Node *curr = result;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            curr->next = head1;
            head1 = head1->next;
        }
        else
        {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if (head1 != NULL)
    {
        curr->next = head1;
    }
    else
    {
        curr->next = head2;
    }
    Node *newHead = result->next;
    delete result;
    return newHead;
}

int main()
{

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int java[n1], dbms[n2], daa[n3];
    for (int i = 0; i < n1; i++)
        cin >> java[i];
    for (int i = 0; i < n2; i++)
        cin >> dbms[i];
    for (int i = 0; i < n3; i++)
        cin >> daa[i];

    Node *head1 = new Node(java[0]);
    Node *curr = head1;
    for (int i = 1; i < n1; i++)
    {
        curr->next = new Node(java[i]);
        curr = curr->next;
    }

    Node *head2 = new Node(dbms[0]);
    curr = head2;
    for (int i = 1; i < n2; i++)
    {
        curr->next = new Node(dbms[i]);
        curr = curr->next;
    }

    Node *head3 = new Node(daa[0]);
    curr = head3;
    for (int i = 1; i < n3; i++)
    {
        curr->next = new Node(daa[i]);
        curr = curr->next;
    }

    Node *head = mergeTwoSortedLinkedLists(head1, head2);
    head = mergeTwoSortedLinkedLists(head, head3);

    cout << "students having all three courses are: " << endl;

    curr = head;
    while (curr != NULL)
    {
        int count = 1;
        while (curr->next != NULL && curr->data == curr->next->data)
        {
            count++;
            curr = curr->next;
        }
        if (count == 3)
        {
            cout << curr->data << " ";
        }
        curr = curr->next;
    }
    return 0;
}
