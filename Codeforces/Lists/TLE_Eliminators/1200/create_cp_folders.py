import os

# The template code to be written to each main.cpp
cpp_template = """#include <bits/stdc++.h>
using ll = long long;
#define mod 1000000007
#define pb push_back
#define asort(a) sort(a.begin(), a.end())
#define vsort(a) sort(a.rbegin(), a.rend())
#define toLow transform(s.begin(), s.end(), s.begin(), ::tolower)
#define floop(n) for (int i = 0; i < n; i++)
#define floop2(n) for (int j = 0; j < n; j++)
#define all(a) a.begin(), a.end()
#define vec(a, n) vector<ll> a(n)
#define cin(a, n)               \\
    for (int i = 0; i < n; i++) \\
    cin >> a[i]
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int N = 1e7 + 10;
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void solve()
{
    
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
"""

def create_folders():
    # Loop from 1 to 31
    for i in range(1, 32):
        folder_name = str(i)
        
        # Create folder if it doesn't exist
        if not os.path.exists(folder_name):
            os.makedirs(folder_name)
            print(f"Created folder: {folder_name}")
        else:
            print(f"Folder already exists: {folder_name}")

        # Path to the main.cpp file
        file_path = os.path.join(folder_name, "main.cpp")

        # Write or overwrite the main.cpp file
        with open(file_path, "w") as f:
            f.write(cpp_template)
            print(f"Created/Updated {file_path}")

        # Create input.txt and output.txt files
        input_path = os.path.join(folder_name, "input.txt")
        output_path = os.path.join(folder_name, "output.txt")

        # Create empty files
        with open(input_path, "w") as f:
            pass
        with open(output_path, "w") as f:
            pass
        
        print(f"Created input.txt and output.txt in {folder_name}")

if __name__ == "__main__":
    create_folders()
