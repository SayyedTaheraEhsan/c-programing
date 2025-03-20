/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode*reverse_LL(ListNode*head){
        if(head==nullptr || head->next==nullptr)return head;
        ListNode*last=nullptr;
        ListNode*prev=head;
        ListNode*curr = head->next;
        while(curr!=nullptr){
            prev->next = last;
            last=prev;
            prev=curr;
            curr=curr->next;
        }
        prev->next = last;
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode*newhead = head;
        newhead=reverse_LL(newhead);
        ListNode*last=newhead;
        ListNode*temp = newhead->next;
        int maxi = newhead->val;
        while(temp!=nullptr){
            if(temp->val<maxi){
                ListNode*curr = temp;
                temp=temp->next;
                last->next = temp;
            }else{
                maxi=max(maxi,temp->val);
                last=temp;
                temp=temp->next;
            }
        }
        newhead = reverse_LL(newhead);
        return newhead;
    }
};