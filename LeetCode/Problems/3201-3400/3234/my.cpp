#include <bits/stdc++.h>
using namespace std;
// hard question, even though its a medium
// i can iterate thorough string n^2
int numberOfSubstrings(string s)
{
    int n = s.size();
    // its a complex question of counting number of 1s in a binary string.
    // sliding window of size 2 to n-1
    int count1 = 0;
    for (char c : s)
    {
        if (c == '1')
            count1++;
    }
    int count0 = n - count1;

}

int main()
{
}