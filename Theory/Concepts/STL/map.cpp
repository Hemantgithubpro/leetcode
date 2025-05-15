#include <bits/stdc++.h>
using namespace std;

// Syntax:
// map<key_type, value_type> mpp;
// key_type: Data type of key. value_type: Data type of value. mpp: Named assigned to the map.
// Important operations: insertion, accessing, updating, finding, traversing, deleting

// insertion: avg TC = O(log n)
void insertion() {
    map<int, string> m = {{2, "For"}, {3, "Geeks"}};

    // Inserting a key value pair
    m.insert({4, "Geeks"});

    for (auto x: m)
        cout << x.first << " " << x.second<< endl;
}

// accessing elements
void accessing() {
    map<int, string> mpp = {
        {1, "Geeks"},
        {2, "For"},
        {3, "C++"}
    };

    // Access value associated with key 2 using [] operator
    cout << mpp[2] << endl;

    // Access value associated with key 1 using at() function
    cout << mpp.at(1) << endl;
}

// updating elements
void updating() {
    map<int, string> mpp = {
        {1, "Geeks"},
        {2, "For"},
        {3, "C++"}
    };

    // Updating value associated with key 2 using [] operator
    mpp[2] = "By";
    cout << mpp[2] << endl;

    // Updating value associated with key 1 using at() function
    mpp.at(1) = "Tips";
    cout << mpp.at(1) << endl;
}

// finding elements
void finding() {
    map<int, string> mpp = {
        {1, "Geeks"},
        {2, "For"},
        {3, "C++"}
    };

    // Finding element with key 2
    auto it = mpp.find(2);

    if (it != mpp.end())
        cout << it->first << ": " << it->second << endl;
    else
        cout << "Not Found" << endl;
}

// traversing: O(n)
void traversing() {
    map<int, string> mpp = {
        {1, "Geeks"},
        {2, "For"},
        {3, "C++"}
    };

    // Traversing using iterators with loop
    for (auto it = mpp.begin(); it != mpp.end(); it++)
        cout << it->first << ": " << it->second << endl;
}

// deleting elements
void deleting() {
    map<int, string> mpp = {
        {1, "Geeks"},
        {2, "For"},
        {3, "C++"}
    };

    // Delete element with key 2
    mpp.erase(2);

    // Delete first element
    mpp.erase(mpp.begin());

    for (auto it = mpp.begin(); it != mpp.end(); it++)
        cout << it->first << ": " << it->second << endl;
}

int main() {
    // Uncomment the function calls to test each operation
    insertion();
    // accessing();
    // updating();
    // finding();
    // traversing();
    // deleting();
}