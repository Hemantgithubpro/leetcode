#include <bits/stdc++.h>
using namespace std;
// memoized version, now next version is bottom up approach
int m,n;

int solve(int i,int j, vector<vector<int>>&matrix,vector<vector<int>>&memo){
    if(i>=m||j>=n) return 0;
    if(matrix[i][j]==0) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    int right=solve(i,j+1,matrix,memo);
    int diag=solve(i+1,j+1,matrix,memo);
    int below=solve(i+1,j,matrix,memo);

    return memo[i][j]=1+min({right,diag,below});
}
    int countSquares(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>> memo(m+1,vector<int>(n+1,-1));
        int result=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                    result+=solve(i,j,matrix,memo);
                }
            }
        }
        return result;
    }