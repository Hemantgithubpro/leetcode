#include <bits/stdc++.h>
using namespace std;

// Use long long for values and K
long long N_ll, K_ll;
vector<long long> A, BB;
int S;          // Block size
int num_blocks; // Number of blocks

// Node struct is the same as in the segment tree solution
struct Node
{
    long long score_if_false;
    bool end_state_if_false;
    long long score_if_true;
    bool end_state_if_true;
};

vector<Node> block_info;

// Merge function is also identical
Node merge(Node &left, Node &right)
{
    Node res;
    // Case 1: Initial state is false
    res.score_if_false = left.score_if_false;
    if (left.end_state_if_false)
    {
        res.score_if_false += right.score_if_true;
        res.end_state_if_false = right.end_state_if_true;
    }
    else
    {
        res.score_if_false += right.score_if_false;
        res.end_state_if_false = right.end_state_if_false;
    }
    // Case 2: Initial state is true
    res.score_if_true = left.score_if_true;
    if (left.end_state_if_true)
    {
        res.score_if_true += right.score_if_true;
        res.end_state_if_true = right.end_state_if_true;
    }
    else
    {
        res.score_if_true += right.score_if_false;
        res.end_state_if_true = right.end_state_if_false;
    }
    return res;
}

// Recomputes the info for a single block
void recompute_block(int block_idx)
{
    int start_idx = block_idx * S;
    int end_idx = min((int)N_ll - 1, (block_idx + 1) * S - 1);

    // Create a node for the first element in the block
    bool p_start = (A[start_idx] + K_ll < BB[start_idx]);
    bool q_start = (BB[start_idx] + K_ll < A[start_idx]);
    Node res;
    res.end_state_if_false = p_start;
    res.score_if_false = p_start ? BB[start_idx] : A[start_idx];
    res.end_state_if_true = !q_start;
    res.score_if_true = q_start ? A[start_idx] : BB[start_idx];

    // Iteratively merge the rest of the elements
    for (int i = start_idx + 1; i <= end_idx; ++i)
    {
        bool p_i = (A[i] + K_ll < BB[i]);
        bool q_i = (BB[i] + K_ll < A[i]);
        Node current_element_node;
        current_element_node.end_state_if_false = p_i;
        current_element_node.score_if_false = p_i ? BB[i] : A[i];
        current_element_node.end_state_if_true = !q_i;
        current_element_node.score_if_true = q_i ? A[i] : BB[i];

        res = merge(res, current_element_node);
    }
    block_info[block_idx] = res;
}

// Calculates total score by chaining blocks
long long get_total_score()
{
    long long total_score = 0;
    bool current_state = false; // Initial state is always false
    for (int i = 0; i < num_blocks; ++i)
    {
        if (!current_state)
        {
            total_score += block_info[i].score_if_false;
            current_state = block_info[i].end_state_if_false;
        }
        else
        {
            total_score += block_info[i].score_if_true;
            current_state = block_info[i].end_state_if_true;
        }
    }
    return total_score;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    N_ll = n;
    K_ll = k;

    A.resize(N_ll);
    BB.resize(N_ll);
    for (int i = 0; i < N_ll; ++i)
        cin >> A[i];
    for (int i = 0; i < N_ll; ++i)
        cin >> BB[i];

    S = sqrt(N_ll);
    if (S == 0)
        S = 1; // Handle case N=0
    num_blocks = (N_ll + S - 1) / S;
    block_info.resize(num_blocks);

    for (int i = 0; i < num_blocks; ++i)
    {
        recompute_block(i);
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int type, p;
        long long x;
        cin >> type >> p >> x;
        p--; // 0-based index

        if (type == 1)
        {
            A[p] = x;
        }
        else
        {
            BB[p] = x;
        }

        recompute_block(p / S);
        cout << get_total_score() << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}