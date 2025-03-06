// did it myself but this was not the optimal solution

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        stack<int> st;
        while(head!=nullptr){
            st.push(head->val);
            head=head->next;
        }
        bool ans=true;
        while(temp!=nullptr){
            if(temp->val!=st.top()) ans=false;
            st.pop();
            temp=temp->next;
        }
        return ans;
}

int main(){
  ListNode* head=new ListNode(1);
  head->next=new ListNode(2);
  head->next->next=new ListNode(2);
  head->next->next->next=new ListNode(1);
  cout<<isPalindrome(head);
}