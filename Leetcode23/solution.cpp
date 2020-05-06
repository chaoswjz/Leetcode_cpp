/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size() == 0)
            return NULL;
        if(lists.size() == 1)
            return lists[0];
        
        ListNode* res = lists[0];
        
        for(int i = 1; i < lists.size(); i++)
        {
            res = merge2Lists(res, lists[i]);
        }
        
        return res;
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode prehead(0);
        ListNode* h = &prehead;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                h->next = l1;
                l1 = l1->next;
            }
            else
            {
                h->next = l2;
                l2 = l2->next;
            }
            h = h->next;
        }
        h->next = l1?l1:l2;
        
        return prehead.next;
    }
};
