
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        // Remove matching nodes from the beginning
        while (head != NULL && head->val == val) {
            head = head->next;
        }

        // Remove matching nodes from the rest of the list
        ListNode* current = head;

        while (current != NULL && current->next != NULL) {
            if (current->next->val == val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};

