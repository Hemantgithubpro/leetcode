#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int binarystringtodecimal(string &s)
{
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ans += pow(2, n - i - 1);
        }
    }
    return ans;
}
int getDecimalValue(ListNode *head)
{
    string s = "";
    while (head != nullptr)
    {
        cout << head->val << " ";
        s += to_string(head->val);
        head = head->next;
    }
    cout << endl;
    return binarystringtodecimal(s);
}

// soln
int getDecimalValue(ListNode *head)
{
    int result = 0;
    while (head != nullptr)
    {
        result = (result << 1) | head->val;
        head = head->next;
    }
    return result;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(0);
    cout << getDecimalValue(head);
    // string s = "1010";
    // cout << binarystringtodecimal(s);
    return 0;
}