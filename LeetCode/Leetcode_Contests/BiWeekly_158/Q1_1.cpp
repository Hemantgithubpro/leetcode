#include <bits/stdc++.h>
using namespace std;

int gety(int i, int j, int k, vector<int> &y)
{
    return y[i] + y[j] + y[k];
}
bool isvalid(int i, int j, int k, vector<int> &x)
{
    if (x[i] != x[j] && x[j] != x[k] && x[k] != x[i])
        return true;
    return false;
}
int maxSumDistinctTriplet(vector<int> &x, vector<int> &y)
{
    // we need to maximize gety()
    // i knew this method got tle. because its O(n^3)
    int ans = -1;
    int n = x.size();
    
    // new vector
    vector<pair<int,int>> xy;
    for(int i=0; i<n; i++){
        pair<int,int> temp={x[i],y[i]};
        xy.push_back(temp);
    }

    // sort
    sort(xy.begin(),xy.end());

    // unordered_set<pair<int,int>> us;

    for(int i=0; i<n; i++){
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (isvalid(i, j, k, x))
                {
                    ans = max(ans, gety(i, j, k, y));
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> x={1,2,1,3,2}; 
    vector<int> y={5,3,4,6,2}; 
    cout<<maxSumDistinctTriplet(x,y);
}