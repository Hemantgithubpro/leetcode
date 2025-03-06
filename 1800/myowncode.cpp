// did it myself, and this was the optimal solution. oe thing it took me 3 attempts
#include <bits/stdc++.h>
using namespace std;

int maxAscendingSum(vector<int>& nums) {
  int sum=nums[0];
  int cur;
  int temp=nums[0];
  for(int i=0; i<nums.size()-1; i++){
      if(nums[i]>=nums[i+1]){
          cur=i+1;
          sum=0;
      }
      sum+=nums[i+1];
      temp=max(sum,temp);
  }
  return temp;
}

int main(){
  vector<int> n={1,3,4,5,2,7,8,9,10}; //2+7+8+9+10=36
  cout<<maxAscendingSum(n);

}