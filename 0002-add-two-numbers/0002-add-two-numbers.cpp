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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode* head = new ListNode(-1);
        ListNode*mover = head;
        while(l1 || l2 || carry)
        {
            int num1 = 0;
            int num2 = l2!=NULL?l2->val:0;
            if(l1!=nullptr)
            {
                num1 = l1->val;
                l1 = l1->next;
            }
            if(l2!=nullptr)
            {
                num2 = l2->val;
                l2 = l2->next;
            }
            mover -> next = new ListNode((num1+num2+carry)%10);
            carry = (num1+num2+carry)/10;
            mover = mover -> next;
        }
        return head->next;
    }
};