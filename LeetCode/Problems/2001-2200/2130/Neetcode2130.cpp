// Optimal approach without wasting any extra space is to reverse the other half of linkedlist so that we can apply two pointer approach from extreme ends to middle.

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};


int  pairSum(ListNode* head){
  int sum=0;
  ListNode* half=head;
  ListNode* fullend=head;
  while(fullend!=nullptr){
    half=half->next;
    fullend=fullend->next->next;
  }
  cout<<fullend->val<<endl;
  ListNode* prev=nullptr;
  ListNode* curr=half;
  prev=curr;
  while(curr!=nullptr){
    ListNode* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
  }
  // while(head!=half){
  //   sum=max(sum,head->val+fullend->val);
  //   head=head->next;
  //   fullend=fullend->next;
  // }
  // sum=max(sum,half->val+fullend->val);
  return sum;
        
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    // 1->2->3->4->5->6
    pairSum(head);
    return 0;
}