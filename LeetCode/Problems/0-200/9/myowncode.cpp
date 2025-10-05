// did it myself without any help but this was not the optimal solution
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
        if(x<0) return false;
        int temp=x;
        stack<int> a;
        while(temp!=0){
            a.push(temp%10);
            temp/=10;
        }
        bool ans=true;
        while(!a.empty()){
            if(a.top()!=x%10) ans=false;
            a.pop();
            x=x/10;
        }
        return ans;
    }

int main(){
  int x=12231;
  cout<<isPalindrome(x);
}