// the code is mostly working, just an error of time limit exceeded is coming.
// because i know its not the most optimised solution, so i need to find a better way.
#include <bits/stdc++.h>
using namespace std;


int findFirst0(vector<int>& a) {
for (int i = 0; i < a.size() - 2; i++) { // Ensure the window of size 3 fits
    if (a[i] == 0) return i;
}
return -1;
}

// Function to flip the three elements given the first index of occurrence of 0
vector<int>& b(int index, vector<int>& c) {
    for (int i = index; i < index + 3; i++) {
        if (c[i] == 0) c[i] = 1;
        else c[i] = 0;
    }
    return c;
}

bool check(vector<int>& d){
    for(int i=0; i<d.size(); i++) if(d[i]==0) return false;
    return true;
}

int minOperations(vector<int>& nums) {
    if(check(nums)) return 0;
    int num = 0; // Count of operations

    while (true) {
        // Find the first occurrence of 0
        int index = findFirst0(nums);

        // If no 0 is found, break the loop
        if (index == -1) break;
        
        // Flip the window of size 3 starting from the index
        b(index, nums);

        // Increment the operation count
        num++;
    }

    if(num>0 && check(nums)) return num;
    else return -1;
}

int main(){
    
}