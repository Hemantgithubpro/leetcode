#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin>>n;
    int remaining=25-n;
    int ans=remaining/4;
    if(remaining%4!=0) ans++;
    cout<<ans;
}
