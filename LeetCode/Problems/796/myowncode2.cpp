#include <bits/stdc++.h>
using namespace std;

vector<int> a(string s, string goal, queue<char> g){
    vector<int> b;
    int j=0;
    while(j<s.size()){
        if(s[j]==g.front()) b.push_back(j);
        j++;
    }
    return b;
}

bool d(string s, string goal, int j){
    if(s.size()!=goal.size()) return false;
    queue<char> g;
    for(int i=0; i<goal.size(); i++){
        g.push(goal[i]);
    }
    
    // finding first element of in s
    
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

bool rotateString(string s, string goal) {
    queue<char> g;
    for(int i=0; i<goal.size(); i++){
        g.push(goal[i]);
    }
    vector<int> c=a(s,goal,g);
    int j=0;
    for(int i=0; i<c.size(); i++){
        while(j<s.size()){
            j++;
            if(s[j]==g.front()) break;
        }
        if(d(s,goal,j)) return true;
    }
    return false;
}

int main(){
    string s="defdefdefabcabc";
    string goal="defdefabcabcdef";
    cout<<rotateString(s,goal);
}