#include <bits/stdc++.h>
using namespace std;

// 1. simple sort
// 2. sort with custom comparator
// 3. sort with lambda function
// 4. sort with custom comparator and lambda function

// lambda function is a function that is defined in the same line as it is called. It is used to create a function object that can be passed as an argument to another function. It is a way to create a function without having to define it separately. It is also known as an anonymous function or a lambda expression.
// [](pair<int,int> a, pair<int,int> b) {
//     return a.first < b.first;
// }


int main(){
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    sort(arr.begin(), arr.end()); // sort in ascending order
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<pair<int,int>> arr2 = {{5,2}, {9,1}, {5,6}};
    sort(arr2.begin(), arr2.end(), [](pair<int,int> a, pair<int,int> b){
        return a.first < b.first; // sort by first element of pair
    });
    for(int i=0; i<arr2.size(); i++){
        cout << arr2[i].first << " " << arr2[i].second << endl;
    }

    vector<vector<int>> arr3 = {{5,2}, {9,1}, {5,6}};
    sort(arr3.begin(), arr3.end(), [](vector<int> a, vector<int> b){
        return a[0] < b[0]; // sort by first element of vector
    });
    for(int i=0; i<arr3.size(); i++){
        cout << arr3[i][0] << " " << arr3[i][1] << endl;
    }

    // sort with lambda function
    vector<int> arr4 = {5, 2, 9, 1, 5, 6};
    sort(arr4.begin(), arr4.end(), [](int a, int b){
        return a > b; // sort in descending order
    });
    for(int i=0; i<arr4.size(); i++){
        cout << arr4[i] << " ";
    }

}