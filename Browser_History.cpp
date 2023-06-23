#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<string> linkedList;
    string address;

    while (cin >> address)
    {
        if (address == "end")
            break;

        linkedList.push_back(address);
    }

    int Q;
    cin >> Q;

    string command, addressToVisit;
    cin >> command >> addressToVisit;

    auto current = linkedList.begin();
    while (*current != addressToVisit)
        ++current;

    cout << addressToVisit << endl;

    for (int i = 1; i < Q; ++i)
    {
        cin >> command;

        if (command == "next")
        {
            if (++current != linkedList.end())
            {
                // ++current;
                cout << *current << endl;
            }
            else
            {
                --current;
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            if (current != linkedList.begin())
            {
                --current;
                cout << *current << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "visit")
        {
            cin >> addressToVisit;
            auto it = find(linkedList.begin(), linkedList.end(), addressToVisit);
            if (it != linkedList.end())
            {
                current = it;
                cout << addressToVisit << endl;
            }
            else
                cout << "Not Available" << endl;
        }
    }

    return 0;
}