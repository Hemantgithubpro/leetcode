#include <bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n) {
    if (n == 0) return false;
    while(n % 3 == 0) n /= 3;    
    return n == 1;
}

bool isPowerOfThreeRecursive(int n) {
	if(n <= 1) return n == 1;
	return n % 3 == 0 && isPowerOfThree(n / 3);
}

int main(){
    
}
