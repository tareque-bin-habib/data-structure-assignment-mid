#include <bits/stdc++.h>
using namespace std;
void printLinkedList(list<int> myNodeList)
{
    for (int value : myNodeList)
    {
        cout << value << " ";
    }
    cout << endl;
}

list<int> removeTheDuplicates(list<int> myNodeList)
{
    set<int> uniqueValue;
    list<int> uniqueList;

    for (int value : myNodeList)
    {
        uniqueValue.insert(value);
    }

    for (int value : uniqueValue)
    {
        uniqueList.push_back(value);
    }

    return uniqueList;
}

int main()
{
    list<int> myNodeList;

    int value;
    while (cin >> value && value != -1)
    {
        myNodeList.push_back(value);
    }

    list<int> uniqueList = removeTheDuplicates(myNodeList);
    uniqueList.sort();

    printLinkedList(uniqueList);
    return 0;
}