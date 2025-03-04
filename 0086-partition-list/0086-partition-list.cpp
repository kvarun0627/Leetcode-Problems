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
    ListNode* partition(ListNode* head, int x) {
        ListNode*dummy=new ListNode(-201,head);
        ListNode*j=dummy;
        ListNode*i=dummy;
        while(j!=nullptr && j->next!=nullptr)
        {
            if(j->next->val<x)
            {
                ListNode*less=j->next;
                j->next=less->next;
                less->next=i->next;
                i->next=less;
                i=i->next;
                j=j->next;
            }
            else
            {
                j=j->next;
            }
        }
        return dummy->next;
    }
};