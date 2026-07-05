#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val); // create new node
    // conner case
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void deleteNode_at_head(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    Node *deletenode = head;
    head = head->next;
    delete deletenode;
    if (head == NULL)
    {
        tail = NULL;
    }
}

void deleteNode_at_any_pos(Node *&head, int idx)
{
    Node *tmp = head;

    for (int i = 1; i < idx; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            return;
        }
    }
    Node *deletenode = tmp->next;
    tmp->next = tmp->next->next;
    delete deletenode;
}

void delete_at_tail(Node *head, Node *&tail, int idx)
{
    Node *tmp = head;
    for (int i = 1; i < idx; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            return;
        }
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
    tail = tmp;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL) // conner case
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = tail->next; // update tail
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

int linked_list_size(Node *head)
{
    int cnt = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;
    while (q--)
    {
        // print_linked_list(head);
        int x, v;
        cin >> x >> v;
        int size = linked_list_size(head);
        if (x == 0)
        {
            insert_at_head(head, tail, v);
            print_linked_list(head);
            cout << endl;
        }
        else if (x == 1)
        {
            insert_at_tail(head, tail, v);
            print_linked_list(head);
            cout << endl;
        }
        else
        {
            int idx = v;
            if (size <= idx || idx < 0)
            {
                print_linked_list(head);
                cout << endl;
            }
            else
            {
                if (idx == 0)
                {
                    deleteNode_at_head(head, tail);
                    print_linked_list(head);
                    cout << endl;
                }
                else if (idx == size - 1)
                {
                    delete_at_tail(head, tail, v);
                    print_linked_list(head);
                    cout << endl;
                }
                else
                {
                    deleteNode_at_any_pos(head, v);
                    print_linked_list(head);
                    cout << endl;
                }
            }
        }
    }

    return 0;
}