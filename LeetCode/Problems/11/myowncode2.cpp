#include <bits/stdc++.h>
using namespace std;

// 2nd: my own way of two pointer
// i did it myself with my own way, its an amazing feeling. and it was the most optimized way.
int maxArea(vector<int>& height) {
    int area=0;
    int l=0;
    int r=height.size()-1;
    area=(r-l)*(min(height[r],height[l]));
    while(r>l){
        if(height[l]<height[r]){
            l++;
        }
        else{
            r--;
        }
        area=max(area,(r-l)*(min(height[r],height[l])));
    }
    return area;
}

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
    
}