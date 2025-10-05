#include <bits/stdc++.h>
using namespace std;

// method 1
// int xorOperation(int n, int start) {
//     vector<int> a;
//     for(int i=0; i<n; i++){
//         a.push_back(start+2*i);
//     }
//     int ans=0;
//     for(int i=0; i<n; i++){
//         ans = ans^a[i];
//     }
//     return ans;
// }

// method 2
// int xorOperation(int n, int start) {
//     int ans=0;
//     for(int i=0; i<n; i++){
//         ans = ans^(start+2*i);
//     }
//     return ans;
// }

// method 3: finding pattern, i could've but just copied from leetcode solutions
// int XORforN(int val)
// {
//     switch(val & 3)
//     {
//         case 0:
//             return val;
//         case 1:
//             return 1;
//         case 2:
//             return (val + 1);
//         case 3:
//             return 0;
//     }
//     // printf("\n\tshouldn't reach here!");
//     return 0;
// }

// int xorOperation(int n, int start){  
//        return (start & 1 & n) | ((XORforN((start >> 1) + n - 1) ^ XORforN((start >> 1) - 1)) << 1);
// }

int main(){
    
}