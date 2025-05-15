#include <bits/stdc++.h>
using namespace std;

// 1st: brute force
int maxArea(vector<int>& height) {
    int area=0;
    for(int i=0; i<height.size()-1; i++){
        for(int j=i+1; j<height.size(); j++){
            int h=min(height[i],height[j]);
            // int h=height[j];
            int w=j-i;
            area=max(area,h*w);
        }
    }
    return area;
}

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
    
}