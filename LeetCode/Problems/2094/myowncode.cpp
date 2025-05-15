#include <bits/stdc++.h>
using namespace std;
// this solution will be brute force, and i will optimize it later

vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> result;
    unordered_set<int> unique_numbers;
    // sort(digits.begin(),digits.end());
    for(int i = 0; i < digits.size(); i++){
        for(int j = 0; j < digits.size(); j++){
            for(int k = 0; k < digits.size(); k++){
                if(i != j && j != k && i != k ){
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(num % 2 == 0 && num >= 100){
                        unique_numbers.insert(num);
                    }
                }
            }
        }
    }
    for(auto num : unique_numbers){
        result.push_back(num);
    }
    sort(result.begin(), result.end());
    return result;
}

int main(){
    vector<int> digits = {2, 1, 3, 0};
    // sort the digits: {0, 1, 2, 3}
    vector<int> result = findEvenNumbers(digits);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}