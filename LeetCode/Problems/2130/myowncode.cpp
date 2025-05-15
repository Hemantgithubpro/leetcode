// did it myself but it was not the optimal solution

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int pairSum(ListNode* head) {
        int sum=0;
        ListNode* temp=head;
        vector<int> arr;
        int n=0;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
            n++;
        }
        for(int i=0; i<n ; i++){
            int t1=arr[i]+arr[n-1-i];
            int t2=sum;
            sum=max(t1,t2);
        }
        return sum;
        
    }

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    pairSum(head);
    return 0;
}
