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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head= new ListNode(-1);
        ListNode* mover=head;
        int carry=0;
        while(l1 || l2 || carry)
        {
            int a=0;
            if(l1)
            {
                a=l1->val;
                l1=l1->next;
            }
            int b=0;
            if(l2)
            {
                b=l2->val;
                l2=l2->next;
            }

            int num=a+b+carry;
            mover->next= new ListNode(num%10);
            mover=mover->next;
            carry=num/10;
        }
        return head->next;
    }
};