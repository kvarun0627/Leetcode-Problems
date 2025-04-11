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
    void insert_ele(ListNode*j,ListNode*i,ListNode*dup_head)
    {
        ListNode*k=dup_head;
        ListNode*l=dup_head->next;
        while(l!=j && l->val<j->val)
        {
            l=l->next;
            k=k->next;
        }
        i->next=j->next;
        j->next=k->next;
        k->next=j;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode*dup_head=new ListNode(-5001,head);
        ListNode*j=dup_head->next->next;;
        ListNode*i=dup_head->next;;
        while(j)
        {
            if(i->val<=j->val)
            {
                j=j->next;
                i=i->next;
            }
            else
            {
                ListNode*nxt=j->next;
                insert_ele(j,i,dup_head);
                j=nxt;
            }
        }
        return dup_head->next;
    }
};