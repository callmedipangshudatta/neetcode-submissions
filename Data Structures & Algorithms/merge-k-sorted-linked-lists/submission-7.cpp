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
        if(lists.empty()) return nullptr;
        return divide(lists,0,lists.size()-1);
    }
private:
    ListNode* divide(vector<ListNode*>& lists,int left,int right){
        if(left==right){
            return lists[left];
        }
        int mid = left + (right-left)/2;
        ListNode* listsLeft = divide(lists,left,mid);
        ListNode* listsRight = divide(lists,mid+1,right);
        return mergeTwo(listsLeft,listsRight);
    }
    ListNode* mergeTwo(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val<l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1!=nullptr){
            tail->next = l1;
        }else{
            tail->next = l2;
        }
        return dummy.next;
    }
    
};
