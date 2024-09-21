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
private:
    ListNode * reverse(ListNode* head,ListNode* front,int k){
        ListNode * cur=head;
        ListNode * pre=front;
        while(k>0&&cur){
            ListNode * temp =cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
            k--;
        }
        return pre;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode *cnt=head;
        int x=1;
        while(cnt->next){
            x++;
            cnt=cnt->next;
        }
        ListNode dummy(0);
        dummy.next=head;
        ListNode * cur=head;
        ListNode * pre=&dummy;
        while(k<=x){
            ListNode * tail=cur;
            ListNode * nxt=cur;
            for(int i=0;i<k;i++){
                nxt=nxt->next;
            }
            pre->next=reverse(cur,pre,k);
            tail->next=nxt;
            pre=tail;
            cur=nxt;
            x-=k;

        }
        return dummy.next;
    }
};