#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    // Helper function to calculate common prefix length between two strings
    int commonPrefixLength(const string& s1, const string& s2) {
        int len = 0;
        int minLen = min(s1.length(), s2.length());
        
        for (int i = 0; i < minLen; i++) {
            if (s1[i] == s2[i]) {
                len++;
            } else {
                break;
            }
        }
        
        return len;
    }
    
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> answer(n, 0);
        
        if (n <= 2) {
            return answer; // All answers are 0
        }
        
        // Precompute common prefix lengths for all original adjacent pairs
        vector<int> prefixLen(n - 1);
        for (int i = 0; i < n - 1; i++) {
            prefixLen[i] = commonPrefixLength(words[i], words[i + 1]);
        }
        
        // Precompute prefix maximum from left and right for efficient range max queries
        vector<int> leftMax(n - 1), rightMax(n - 1);
        
        leftMax[0] = prefixLen[0];
        for (int i = 1; i < n - 1; i++) {
            leftMax[i] = max(leftMax[i - 1], prefixLen[i]);
        }
        
        rightMax[n - 2] = prefixLen[n - 2];
        for (int i = n - 3; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], prefixLen[i]);
        }
        
        for (int removeIdx = 0; removeIdx < n; removeIdx++) {
            int maxPrefixLen = 0;
            
            if (removeIdx == 0) {
                // Removing first element: use pairs from index 1 onwards
                if (n > 2) {
                    maxPrefixLen = rightMax[1];
                }
            } else if (removeIdx == n - 1) {
                // Removing last element: use pairs up to index n-3
                if (n > 2) {
                    maxPrefixLen = leftMax[n - 3];
                }
            } else {
                // Removing middle element
                // Consider pairs before removeIdx-1
                if (removeIdx > 1) {
                    maxPrefixLen = max(maxPrefixLen, leftMax[removeIdx - 2]);
                }
                // Consider pairs after removeIdx
                if (removeIdx < n - 2) {
                    maxPrefixLen = max(maxPrefixLen, rightMax[removeIdx + 1]);
                }
                // Add the new bridging pair
                int newPrefixLen = commonPrefixLength(words[removeIdx - 1], words[removeIdx + 1]);
                maxPrefixLen = max(maxPrefixLen, newPrefixLen);
            }
            
            answer[removeIdx] = maxPrefixLen;
        }
        
        return answer;
    }
};

// Test function
int main() {
    Solution sol;
    
    // Test case 1
    vector<string> words1 = {"jump", "run", "run", "jump", "run"};
    vector<int> result1 = sol.longestCommonPrefix(words1);
    
    cout << "Input: [";
    for (int i = 0; i < words1.size(); i++) {
        cout << "\"" << words1[i] << "\"";
        if (i < words1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    // Test case 2
    vector<string> words2 = {"dog", "racer", "car"};
    vector<int> result2 = sol.longestCommonPrefix(words2);
    
    cout << "\nInput: [";
    for (int i = 0; i < words2.size(); i++) {
        cout << "\"" << words2[i] << "\"";
        if (i < words2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    cout << "Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}