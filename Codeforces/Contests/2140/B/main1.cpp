#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long x;
        std::cin >> x;
        std::string s = std::to_string(x);
        long long d = s.length();
        
        // We choose d to be one more than the number of digits in x
        // to ensure that y is a positive integer.
        d++;
        
        long long power_of_10 = 1;
        for (int i = 0; i < d; ++i) {
            power_of_10 *= 10;
        }
        
        long long y = power_of_10 - 1 - x;
        
        std::cout << y << std::endl;
    }
    return 0;
}