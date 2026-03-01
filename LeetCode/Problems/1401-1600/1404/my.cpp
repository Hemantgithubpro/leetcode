#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispowerof2(int n){
        if(n & (n-1)) return false;
        return true;
    }
    int numSteps(string s)
    {
        int num=stoi(s,nullptr,2);
        int ans=0;
        while(num!=1){
            
            
            // if(ispowerof2(num)){

            // }
            
            if(num&1){
                num++;
            }
            else{
                num=num/2;
            }
            ans++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string st="1101";
    int a= stoi(st,nullptr, 2);

    // cout<<a;


    int n=6;
    cout<<s.ispowerof2(n);
}