#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> us;
    int searchValue = 42;
    if (us.find(searchValue) != us.end()) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found!" << endl;
    }
}