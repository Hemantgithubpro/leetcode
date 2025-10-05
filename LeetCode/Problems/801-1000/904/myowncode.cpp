#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    map<int,int> mpp;
    int l=0;
    int r=0;
    int maxlen=0;
    // mpp: {value,freq}

    while(r<fruits.size()){
        mpp[fruits[r]]++;
        // all edge cases first then the simple cases
        // if(mpp[fruits[r]]>2){   // if no. of unique fruits exceed 2
        if(mpp.size()>2){   // if no. of unique fruits exceed 2
            while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
        }
        else maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
}

int main(){
    vector<int> fruits = {1,2,3,2,2};
    cout<<totalFruit(fruits);
    
}