#include <bits/stdc++.h>
using namespace std;

// examples of substr library in cpp
void run_substr_examples() {
    string s = "hello world";
    cout << "original: \"" << s << "\"\n";
    cout << "s.substr(0,5): \"" << s.substr(0,5) << "\"\n";     // "hello"
    cout << "s.substr(6): \"" << s.substr(6) << "\"\n";         // "world"
    cout << "s.substr(3,4): \"" << s.substr(3,4) << "\"\n";     // "lo w"
    cout << "s.substr(s.size()): \"" << s.substr(s.size()) << "\" (empty)\n";

    try {
        // pos > size throws out_of_range
        cout << "s.substr(100): ";
        cout << s.substr(100) << "\n";
    } catch (const out_of_range& e) {
        cout << "caught out_of_range: " << e.what() << "\n";
    }
}

// run examples before main
struct SubstrAutoRunner { SubstrAutoRunner(){ run_substr_examples(); } } _substr_auto_runner;


int main(){
    
}