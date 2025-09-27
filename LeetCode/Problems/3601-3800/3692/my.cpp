#include <bits/stdc++.h>
using namespace std;

string majorityFrequencyGroup(string s)
{
    unordered_map<char, int> freq;
    for(char c:s)
        freq[c]++;
    
    // since the constraints are so small, i can make it n^2
    vector<int> groups(s.size());
    for(char c:s){
        int frq=freq[c];
        groups[frq]++;
    }
    int maxi=*max_element(groups.begin(),groups.end());
    
    

}

int main()
{
}