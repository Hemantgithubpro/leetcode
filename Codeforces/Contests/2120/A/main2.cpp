#include <bits/stdc++.h>
using namespace std;

void solve(int l1, int b1, int l2, int b2, int l3, int b3)
{
    // Try all orientations for each rectangle
    vector<pair<int,int>> rects[3];
    rects[0] = {{l1,b1}, {b1,l1}};
    rects[1] = {{l2,b2}, {b2,l2}};
    rects[2] = {{l3,b3}, {b3,l3}};
    
    for(auto r1 : rects[0]) {
        for(auto r2 : rects[1]) {
            for(auto r3 : rects[2]) {
                int a1 = r1.first, b1 = r1.second;
                int a2 = r2.first, b2 = r2.second;
                int a3 = r3.first, b3 = r3.second;
                
                // Try all 6 permutations of the three rectangles
                vector<vector<pair<int,int>>> perms = {
                    {{a1,b1}, {a2,b2}, {a3,b3}},
                    {{a1,b1}, {a3,b3}, {a2,b2}},
                    {{a2,b2}, {a1,b1}, {a3,b3}},
                    {{a2,b2}, {a3,b3}, {a1,b1}},
                    {{a3,b3}, {a1,b1}, {a2,b2}},
                    {{a3,b3}, {a2,b2}, {a1,b1}}
                };
                
                for(auto perm : perms) {
                    int l1 = perm[0].first, w1 = perm[0].second;
                    int l2 = perm[1].first, w2 = perm[1].second;
                    int l3 = perm[2].first, w3 = perm[2].second;
                    
                    // Case 1: All three stacked vertically (same width)
                    if(l1 == l2 && l2 == l3) {
                        int total_height = w1 + w2 + w3;
                        if(total_height == l1) {
                            cout << "YES" << endl;
                            return;
                        }
                    }
                    
                    // Case 2: All three side by side horizontally (same height)
                    if(w1 == w2 && w2 == w3) {
                        int total_width = l1 + l2 + l3;
                        if(total_width == w1) {
                            cout << "YES" << endl;
                            return;
                        }
                    }
                      // Case 3: First rectangle spans full width, other two stacked vertically
                    if(l2 == l3 && w2 + w3 == w1 && l1 + l2 == w1) {
                        cout << "YES" << endl;
                        return;
                    }
                    
                    // Case 4: First rectangle spans full height, other two side by side
                    if(w2 == w3 && l2 + l3 == l1 && w1 + w2 == l1) {
                        cout << "YES" << endl;
                        return;
                    }
                    
                    // Case 5: Second rectangle spans full width, first and third stacked
                    if(l1 == l3 && w1 + w3 == w2 && l2 + l1 == w2) {
                        cout << "YES" << endl;
                        return;
                    }
                    
                    // Case 6: Second rectangle spans full height, first and third side by side
                    if(w1 == w3 && l1 + l3 == l2 && w2 + w1 == l2) {
                        cout << "YES" << endl;
                        return;
                    }
                    
                    // Case 7: Third rectangle spans full width, first and second stacked
                    if(l1 == l2 && w1 + w2 == w3 && l3 + l1 == w3) {
                        cout << "YES" << endl;
                        return;
                    }
                    
                    // Case 8: Third rectangle spans full height, first and second side by side
                    if(w1 == w2 && l1 + l2 == l3 && w3 + w1 == l3) {
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }
    }
    
    cout << "NO" << endl;
}

int main()
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
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        solve(l1, b1, l2, b2, l3, b3);
    }

    return 0;
}