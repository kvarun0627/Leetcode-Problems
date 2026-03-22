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
    ListNode* removeNodes(ListNode* head) 
    {
        ListNode* mover = head;
        stack<ListNode*>st;
        while(mover)
        {
            while(!st.empty() && st.top()->val < mover->val)
            {
                st.pop();
            }
            st.push(mover);
            mover = mover->next;
        }

        head = nullptr;
        while(!st.empty())
        {
            st.top()->next = head;
            head = st.top();
            st.pop(); 
        }
        return head;
    }
};