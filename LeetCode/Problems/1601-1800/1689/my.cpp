#include <bits/stdc++.h>
using namespace std;

// so much simple, just get the max digit from the num, and thats the answer.
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char& c : n) ans = max(ans, c - '0');
        return ans;
    }
};

int main(){
    
}