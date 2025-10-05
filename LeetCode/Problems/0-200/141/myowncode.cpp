#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// in this question: two or more nodes can have same value, so i need to compare them with temp nodes only.
bool hasCycle(ListNode *head) {
    ListNode* temp=head;
    ListNode* temp2=head;
    unordered_set<int> us;
    if(temp==nullptr) return false;
    while(temp->next!=nullptr){
        auto it=us.find(temp->val);
        if(it==us.end()) us.insert(temp->val);
        else return true;
        temp=temp->next;
    }

    return false;
}

int main(){
    
}