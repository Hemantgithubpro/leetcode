#include<bits/stdc++.h>
using namespace std;

// insertion: avg TC=O(1)
void insertion(){
    // insertion
    // We cannot specify the position to insert the element as it is automatically decided by its hashed value.
    unordered_set<int> us;

    us.insert(11);
    us.insert(17);
    us.insert(15);

    for(auto x:us){
        cout<<x<<endl;
    }
}

// accessing elements: not useful in unordered set
void accessing(){
    unordered_set<int> us = {11, 21, 31, 41, 51};
    
    // Accessing second element
    auto it = next(us.begin(), 2);  // unordered set is indexed from 1, not from 0 as in arrays.
    cout << *it;
    
}

// updating elements: cannot be changed after insertion

// finding elements: finding if an element exists in hash map or not, very useful as it has O(1) complexity
void finding(){
    unordered_set<int> us = {10, 20, 30, 40, 50};

    // Finding 40
    auto it = us.find(40);
    
    if (it != us.end()) cout << *it;
    else cout << "Element not Found!";

}

// traversing
void traversing(){
    unordered_set<int> us = {1, 2, 3, 4, 5};
    
    // Using iterator in loop
    for(auto it = us.begin(); it != us.end(); it++)
        cout << *it << " ";
}

//deleting
void deleting(){
    unordered_set<int> us = {10, 20, 30, 40, 50};

    // Delete element by value
    us.erase(50);
    
    // Delete element by position
    us.erase(us.begin());
    // us.erase(next(us.begin(),1));
    
    for(auto x : us)
        cout << x << " ";
}

int main(){
    // auto x=2;
    // cout<<x<<endl;
    // cout<<typeid(x).name();
}