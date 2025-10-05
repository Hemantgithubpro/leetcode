// https://www.hackerrank.com/challenges/extra-long-factorials/problem
#include <bits/stdc++.h>
using namespace std;

void extraLongFactorials(int n){
    // for this i'll use a vector<int> to store digits of each number and then find its factorial.
    vector<int> result = {1};  // Start with factorial = 1

    for(int i = 2; i <= n; i++) {
        int carry = 0;
        for(int j = 0; j < result.size(); j++) {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }
        
        while(carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Print the factorial from most significant digit
    for(int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
}

int main(){
    // we've to display the factorials of really long numbers.
    // even "long long" can only store factorials of upto n=20.

    int n=25;
    extraLongFactorials(n);
}