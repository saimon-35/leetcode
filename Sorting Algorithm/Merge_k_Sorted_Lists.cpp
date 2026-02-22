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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1 -> val <= temp2 -> val){
                tail -> next = temp1;
                temp1 = temp1 -> next;
            }
            else{
                tail -> next = temp2;
                temp2 = temp2 -> next;
            }
            tail = tail -> next;
        }
        tail -> next = temp1 ? temp1 : temp2;
        return dummy.next;
    }
    void mergesort(int s, int e, vector<ListNode*>&lists){
        if(s < e){
            int m = (s + e) / 2;
            mergesort(s, m, lists);
            mergesort(m + 1, e, lists);
            ListNode* l1 = lists[s];
            ListNode* l2 = lists[m + 1];
            lists[s] = merge(l1, l2);
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        mergesort(0, lists.size() - 1, lists);
        return lists.size() == 0 ? nullptr : lists[0];
    }
};
