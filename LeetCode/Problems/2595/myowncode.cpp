#include <bits/stdc++.h>
using namespace std;

vector<int> evenOddBit(int n);

int main(){
    int n=50;
    vector<int> a=evenOddBit(n);
    cout<<a[0]<<" "<<a[1]<<endl;
    return 0;   
}

vector<int> evenOddBit(int n) {
    vector<int> a;
    int even=0;
    int odd=0;
    for(int i=0; i<32; i++){
        if(i%2==0){
            if(n&(1<<i)) even++;
        }
        else{
            if(n&(1<<i)) odd++;
        }
    }
    a.push_back(even);
    a.push_back(odd);
    return a;
}

