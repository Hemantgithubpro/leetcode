#include <bits/stdc++.h>
using namespace std;

// make a vector to store all prime numbers between left and right using Sieve of Eratosthenes
vector<int> sieveofEratosth(int left, int right) {
    int n = right;
    vector<int> primes;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = left; p <= n; p++){
        if (prime[p]) primes.push_back(p);
    }
    return primes;
}

// so the primes are already sorted, we just have to find the lowest (primes[i] - primes[i-1]).
// if there are multiple pairs with the same difference, return the one with the smallest sum.
pair<int,int> findClosestPrimes(vector<int> primes){
    int minDiff = INT_MAX;
    pair<int,int> closestPrimes={-1,-1};
    for (int i = 1; i < primes.size(); i++){
        if (primes[i] - primes[i-1] < minDiff){
            minDiff = primes[i] - primes[i-1];
            closestPrimes = {primes[i-1],primes[i]};
            // closestPrimes = make_pair(primes[i-1], primes[i]);
        }
    }
    return closestPrimes;
}

vector<int> closestPrimes(int left, int right) {
    vector<int> primes = sieveofEratosth(left, right);
    pair<int,int> closest = findClosestPrimes(primes);
    return {closest.first, closest.second};
}

int main(){
    
}