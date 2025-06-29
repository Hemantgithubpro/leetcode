#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> segments;
        unordered_set<string> seen;
        
        int i = 0;
        while (i < s.length()) {
            string current = "";
            
            // Keep extending current segment until it's unique or we reach end
            while (i < s.length()) {
                current += s[i];
                i++;
                
                // If current segment is unique, break and add it
                if (seen.find(current) == seen.end()) {
                    break;
                }
            }
            
            // Add the segment to result and mark as seen
            segments.push_back(current);
            seen.insert(current);
        }
        
        return segments;
    }
};

// Test function
int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "abbccccd";
    vector<string> result1 = sol.partitionString(s1);
    
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test case 2
    string s2 = "aaaa";
    vector<string> result2 = sol.partitionString(s2);
    
    cout << "\nInput: \"" << s2 << "\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test case 3
    string s3 = "abcabc";
    vector<string> result3 = sol.partitionString(s3);
    
    cout << "\nInput: \"" << s3 << "\"" << endl;
    cout << "Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}