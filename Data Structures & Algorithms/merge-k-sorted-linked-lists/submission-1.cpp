class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Step 1: If the input collection is completely empty, return null
        if (lists.empty()) return nullptr;
        
        // Step 2: Start the divide-and-conquer process from the first list to the last
        return mergeListsHelper(lists, 0, lists.size() - 1);
    }

private:
    // The Divider: Cuts the collection of lists in half recursively (like splitting homework stacks)
    ListNode* mergeListsHelper(vector<ListNode*>& lists, int start, int end) {
        // Base Case 1: If only one stack is left, return it as-is
        if (start == end) return lists[start];
        
        // Base Case 2: If exactly two stacks are left, merge them directly using our worker function
        if (start + 1 == end) return mergeTwoLists(lists[start], lists[end]);
        
        // Find the middle point to split the range of stacks in half
        int mid = start + (end - start) / 2;
        
        // Recursively sort and merge the left group
        ListNode* left = mergeListsHelper(lists, start, mid);
        
        // Recursively sort and merge the right group
        ListNode* right = mergeListsHelper(lists, mid + 1, end);
        
        // Finally, merge the combined left group with the combined right group
        return mergeTwoLists(left, right);
    }

    // The Weaver: Takes two sorted lists and weaves them into one sorted list element-by-element
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Create a temporary "dummy" node to act as a safe anchor for our new chain
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Loop while both lists still have elements remaining
        while (l1 && l2) {
            // Compare the top items of both lists
            if (l1->val < l2->val) {
                tail->next = l1; // Attach l1's item because it's smaller
                l1 = l1->next;   // Move l1 forward to the next item
            } else {
                tail->next = l2; // Attach l2's item because it's smaller
                l2 = l2->next;   // Move l2 forward to the next item
            }
            tail = tail->next;   // Advance our new list's tail pointer forward
        }
        
        // If one of the lists ran out of elements, attach the remainder of the other list instantly
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        
        // Return everything starting after the dummy node (the actual merged list)
        return dummy.next;
    }
};