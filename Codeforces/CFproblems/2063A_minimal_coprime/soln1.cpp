#include <bits/stdc++.h>
using namespace std;

bool checkcoprime(int a, int b){
	// we assume a<b.
	for (int i=2; i<min(a,b); i++){
		if(a%i==0 && b%i==0) return false;
	}
	return true;

    // or
    // return __gcd(a, b) == 1;
}

int count_minimal_coprime_segments(int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            if (checkcoprime(i, j)) {
                bool is_minimal = true;
                for (int k = i; k < j; k++) {
                    if (checkcoprime(i, k)) {
                        is_minimal = false;
                        break;
                    }
                }
                if (is_minimal) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
	int n;
	cin>>n;
	// pair<int,int> arr[n];
    // // arr[0]=[1,10] => 
	// for(int i=0; i<n; i++){
    //     cin>>arr[i].first>>arr[i].second;
	// }
    // // arr= [[1,10],[69,420]]
	// for(int i=0; i<n; i++){
    //     // going through each arr[0]=> [1,10]
    //     int count=0;
    //     for(int j=arr[i].first; j<=arr[i].second; j++){
    //         // 'j' starting from 1 going to 10=> j=1,2,3,..,10
    //         for(int k=j; k<=arr[i].second; k++){
    //             // for j=1, k=1,2,3,.,10
    //             if(checkcoprime(j,k)) count++;
    //         }
    //     }
    //     cout<<count<<endl;
	// }

    int larr[n];
    int rarr[n];
    
    for(int i=0; i<n; i++){
        cin >> larr[i] >> rarr[i];
    }
    
    for(int i=0; i<n; i++){
        cout << count_minimal_coprime_segments(larr[i], rarr[i]) << endl;
    }
    
    return 0;
    
}