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

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> us;
        ListNode *curra = headA;
        while (curra != nullptr)
        {
            us.insert(curra);
            curra = curra->next;
        }
        ListNode *currb = headB;
        while (currb != nullptr)
        {
            if (us.find(currb) != us.end())
                return currb;
            us.insert(currb);
            currb = currb->next;
        }
        return nullptr;
    }
};

int main()
{
}