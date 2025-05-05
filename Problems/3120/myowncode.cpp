#include <bits/stdc++.h>
using namespace std;

// could be more optimized by using bit manipulation, but this is a good solution as well
int numberOfSpecialChars(string word) {
    unordered_set<int> us;
    for(int i=0; i<word.size(); i++){
        us.insert(word[i]);
    }
    int ans=0;
    for(int i=0; i<word.size(); i++){
        auto it1=us.find(word[i]+32);
        if(it1!=us.end()) {
            ans++;
            us.erase(word[i]+32);
        }
    }
    return ans;
}

// Time complexity: O(n), where n is the length of the word
// Space complexity: O(n), for the unordered set
int main() {
    string word;
    cin >> word;
    cout << numberOfSpecialChars(word) << endl;
    return 0;
}
