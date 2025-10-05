#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n) {
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary.empty() ? "0" : binary;
}

vector<string> convertVectorToBinary(const vector<int>& decimals) {
    vector<string> binaries;
    for (int num : decimals) {
        binaries.push_back(decimalToBinary(num));
    }
    for (const string& binary : binaries) {
        cout << binary << " ";
    }
    cout << endl;
    return binaries;
}



int main(){
    vector<int> decimals={2,4,5};
    // convertVectorToBinary(decimals);
    int a=3&10&2;
    cout<<a;
    
}