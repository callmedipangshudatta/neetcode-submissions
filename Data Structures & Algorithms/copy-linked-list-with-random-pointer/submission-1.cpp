class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // Step 1: Create copy nodes and interweave them with the original list
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nextNode;
            curr = nextNode;
        }
        
        // Step 2: Assign random pointers for the copied nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // Step 3: Separate the interweaved lists back into two independent lists
        curr = head;
        Node* pseudoHead = new Node(0);
        Node* copyCurr = pseudoHead;
        
        while (curr) {
            copyCurr->next = curr->next;
            copyCurr = copyCurr->next;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        
        return pseudoHead->next;
    }
};