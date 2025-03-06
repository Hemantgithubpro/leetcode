#include <bits/stdc++.h>
using namespace std;

int closestpowerof3(int a){
    int temp=0;
    while(pow(3,temp)<=a){
        temp++;
    }
    return --temp;
}

bool presentinvector(int b, vector<int> &v){
    for(int i=0; i<v.size(); i++){
        if(v[i]==b) return true;
    }
    return false;
}

bool c(int n){
    vector<int> v;
    while(n!=0){
        if(n%3==0){
            if(presentinvector(closestpowerof3(n),v)) return false;
            v.push_back(closestpowerof3(n));
            n=n-pow(3,closestpowerof3(n));
            cout<<n<<endl;
        }
        else if(n%3==1){
            if(presentinvector(0,v)) return false;
            v.push_back(0);
            n--;
            cout<<n<<endl;
        }
        else{
            return false;
        }
    }
    return true;
}

bool checkPowersOfThree(int n) {
    return c(n);
}

int main(){
    cout<<checkPowersOfThree(12);
    // cout<<pow(3,2);
}