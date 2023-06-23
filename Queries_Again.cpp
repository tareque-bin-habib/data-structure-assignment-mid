

#include <bits/stdc++.h>
using namespace std;
class DoublyLinkedListNode
{
public:
    int value;
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode *next;

    DoublyLinkedListNode(int val)
    {
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertNode(int index, int value)
    {
        DoublyLinkedListNode *newNode = new DoublyLinkedListNode(value);

        if (index == 0)
        {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            if (tail == nullptr)
                tail = newNode;
        }
        else
        {
            DoublyLinkedListNode *currentNode = head;
            int currentIndex = 0;

            while (currentNode != nullptr && currentIndex < index)
            {
                currentNode = currentNode->next;
                currentIndex++;
            }

            if (currentNode != nullptr)
            {
                newNode->next = currentNode;
                newNode->prev = currentNode->prev;
                if (currentNode->prev != nullptr)
                    currentNode->prev->next = newNode;
                currentNode->prev = newNode;
                if (currentNode == head)
                    head = newNode;
            }
            else
            {
                if (currentIndex == index)
                {
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
                else
                {
                    cout << "Invalid" << endl;
                    delete newNode;
                    return;
                }
            }
        }

        printListLeftToRight();
        printListRightToLeft();
    }

    void printListLeftToRight()
    {
        DoublyLinkedListNode *currentNode = head;

        cout << "L -> ";
        while (currentNode != nullptr)
        {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void printListRightToLeft()
    {
        DoublyLinkedListNode *currentNode = tail;

        cout << "R -> ";
        while (currentNode != nullptr)
        {
            cout << currentNode->value << " ";
            currentNode = currentNode->prev;
        }
        cout << endl;
    }
};

int main()
{
    int Q;
    cin >> Q;

    DoublyLinkedList linkedList;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;

        linkedList.insertNode(X, V);
    }
    return 0;
}