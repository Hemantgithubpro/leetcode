#include <bits/stdc++.h>
#include <numeric> // for std::lcm

int main(){
    std::cout<<"hello\n";

    // use std::lcm (requires C++17 or later)

    long long a = 3;
    long long b = 4;
    long long l = std::lcm(a,b); // this is compiled with `g++ -std=c++17 c.cpp -o c`
    std::cout<<"lcm = "<<l<<"\n";
    return 0;
}