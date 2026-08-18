class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        // PHASE 1: Find Middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // ✂️ THE CLEAN CUT: Separate List A and List B entirely
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        // PHASE 2: Reverse List B
        ListNode* prev = nullptr;
        ListNode* curr = secondHalf;
        while(curr != nullptr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // PHASE 3: The Zipper Merge
        ListNode* first = head;
        ListNode* second = prev;
        
        while(second != nullptr){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second; // Zip down
            second->next = temp1; // Zip up

            first = temp1;
            second = temp2;
        }
    }
};