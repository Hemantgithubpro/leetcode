#include<bits/stdc++.h>
using namespace std;

// Syntax:
// unordered_map<key_type, value_type> mpp;
// key_type: Data type of key. value_type: Data type of value. mpp: Named assigned to the unordered map.
// most important are: insertion() and finding()

// insertion: avg TC=O(1)
void insertion(){
    unordered_map<int, string> mpp = {{1, "Geeks"}, {2, "For"}, {3, "C++"}};
    mpp[14]="Python";   // mpp[key]=value;  key->value  14->"Python"

    for (auto i : mpp) 
        cout << i.first << ": " << i.second<< endl;
}

// accessing elements: not useful in unordered set
void accessing(){
    unordered_map<int, string> um = {
        {1, "Geeks"}, 
        {2, "For"}, 
        {3, "C++"}
    };

    // Access value associated with key 2
    // using [] operator, not recommended
    cout << um[2] << endl;
    
    // Access value associated with key 1
    // using at() function, recommended
    cout << um.at(1);
    
}

// updating elements
void updating(){
    unordered_map<int, string> um =
    {{1, "Geeks"}, {2, "For"}, {3, "C++"}};

    // Updating value associated with key 2
    // using [] operator
    um[2] = "By";
    cout << um[2] << endl;
    
    // Updating value associated with key 1
    //using at() function
    um.at(1) = "Tips";
    cout << um.at(1);
}

// finding elements
void finding(){
    unordered_map<int, string> um =
    {{1, "Geeks"}, {2, "For"}, {3, "C++"}};
    
    // Finding element with key 2
    auto it = um.find(2);
    
    if (it != um.end())
        cout << it->first << ": " << it->second;
    else cout << "Not Found";

}

// traversing: O(n)
void traversing(){
    unordered_map<int, string> um =
    {{1, "Geeks"}, {2, "For"}, {3, "C++"}};

    // Traversing using iterators with loop
    for(auto it = um.begin(); it != um.end(); it++)
        cout << it->first << ": " << it->second
        << endl;
}

//deleting
void deleting(){
    unordered_map<int, string> um =
    {{1, "Geeks"}, {2, "For"}, {3, "C++"}};
    
    // Delete element which have key 2
    um.erase(2);
    
    // Delete first element
    um.erase(um.begin());
  
    for(auto it = um.begin(); it != um.end(); it++)
        cout << it->first << ": " << it->second
        << endl;
}

int main(){
    // insertion();
    // accessing();
    // finding();
}