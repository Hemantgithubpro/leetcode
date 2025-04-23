#include <bits/stdc++.h>
using namespace std;

// add all digits of a number
int numto(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countLargestGroup(int n)
{
    unordered_map<int,int> um;
    for(int i=1; i<=n; i++){
        int k=numto(i);
        // while(k>9) k=numto(k);
        um[k]++;
    }
    int maxi=0;
    for(int i=1; i<=n; i++){
        maxi=max(maxi,um[i]);
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        if(um[i]==maxi) ans++;
    }
    return ans;
}

int main()
{
    cout<<countLargestGroup(13);
}