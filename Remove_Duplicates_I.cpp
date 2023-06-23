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

void print_node(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void removeTheDuplicates(Node *head)
{
    unordered_set<int> uniqueValues;
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL)
    {
        if (uniqueValues.count(current->val) > 0)
        {

            previous->next = current->next;
            delete current;
            current = previous->next;
        }
        else
        {

            uniqueValues.insert(current->val);
            previous = current;
            current = current->next;
        }
    }
}

Node *sortLinkedList(Node *head)
{
    set<int> sortedValues;
    Node *current = head;
    while (current != NULL)
    {
        sortedValues.insert(current->val);
        current = current->next;
    }

    Node *sortedLinkedList = NULL;
    Node *tail = NULL;
    for (int value : sortedValues)
    {
        Node *newNode = new Node(value);
        if (sortedLinkedList == NULL)
        {
            sortedLinkedList = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return sortedLinkedList;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int value;
    while (cin >> value && value != -1)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    removeTheDuplicates(head);

    head = sortLinkedList(head);

    print_node(head);

    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}