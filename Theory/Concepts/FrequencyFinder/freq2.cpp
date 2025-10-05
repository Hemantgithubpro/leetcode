#include<bits/stdc++.h>
using namespace std;
int main() {
    // Define an array of strings
    vector<string> words = {
        "apple", "banana", "apple", "orange", "banana", "banana", "kiwi", "apple"
    };

    // Create an unordered map to store the frequency of each word
    unordered_map<string, int> frequencyMap;

    // Calculate the frequency of each word
    for (string& word : words) {
        frequencyMap[word]++;
    }

    // Output the frequency of each word
    std::cout << "Word Frequencies:" << std::endl;
    for (auto& pair : frequencyMap) {
        cout << "Word \"" << pair.first << "\": " << pair.second << endl;
    }

    return 0;
}
