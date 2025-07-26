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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*dummy=new ListNode(0);
        ListNode* new_head=dummy;
        ListNode* mover=dummy;

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        for(auto node:lists)
        {
            if(node)
            {
                 pq.push(
                    {node->val,node}
                );
            }
        }

        while(!pq.empty())
        {
            auto [val,node]=pq.top();
            pq.pop();
            ListNode*temp=node->next;
            mover->next=node;
            mover=mover->next;
            mover->next=nullptr;
            if(temp)
            {
                pq.push({temp->val,temp});
            }
        }

        return new_head->next;
    }
};