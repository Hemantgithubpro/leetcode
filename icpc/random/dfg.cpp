#include <iostream>
#include <string>

// A lightweight version of the popular dbg(...) macro
#define dbg(expr) \
    (std::clog << "[" << __FILE__ << ":" << __LINE__ << " (" << __func__ << ")] " \
               << #expr << " = " << (expr) << " (" << typeid(expr).name() << ")\n", (expr))

// A simple recursive function to calculate factorial
int fact(int n) {
    if (n <= 1) {
        return 1;
    }
    // We wrap the recursive calculation in dbg(...) to watch it happen inline
    return dbg(n * fact(n - 1));
}

int main() {
    std::cout << "--- Starting Program ---\n\n";

    int number = 4;
    
    // 1. Debugging a simple variable
    dbg(number);

    // 2. Debugging an expression inside a logic loop
    std::cout << "\nCalculating factorial for " << number << ":\n";
    int result = fact(number);

    std::cout << "\nFinal Result: " << result << "\n";
    std::cout << "\n--- Program Finished ---\n";
    
    return 0;
}
