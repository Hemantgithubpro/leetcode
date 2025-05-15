#include <bits/stdc++.h>
using namespace std;
// tried but failed in testcase 38/57

bool rotateString(string s, string goal) {
    if(s.size()!=goal.size()) return false;
    queue<char> g;
    for(int i=0; i<goal.size(); i++){
        g.push(goal[i]);
    }

    // finding first element of in s
    int j=0;
    while(j<s.size()){
        if(s[j]==g.front()) break;
        j++;
    }
    int temp=j;
    while(j<s.size()){
        if(s[j]==g.front()) g.pop();
        j++;
    }
    for(int k=0; k<temp; k++){
        if(s[k]==g.front()) g.pop();
    }

    if(g.empty()) return true;
    return false;

}

int main(){
    
}