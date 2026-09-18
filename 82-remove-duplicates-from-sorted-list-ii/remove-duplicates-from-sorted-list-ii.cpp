
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* current = head;

        // Remove duplicates from the beginning
        while (current != NULL && current->next != NULL) {

            if (current->val == current->next->val) {

                int value = current->val;

                // Skip all nodes having this value
                while (current != NULL && current->val == value) {
                    current = current->next;
                }

                // If duplicates were at the beginning
                if (head->val == value) {
                    head = current;
                }
            }
            else {
                break;
            }
        }

        // If list is empty or only one node remains
        if (head == NULL) {
            return NULL;
        }

        current = head;

        // Check duplicates in the remaining list
        while (current->next != NULL) {

            if (current->next->next != NULL &&
                current->next->val == current->next->next->val) {

                int value = current->next->val;

                // Skip all duplicate nodes
                while (current->next != NULL &&
                       current->next->val == value) {
                    current->next = current->next->next;
                }
            }
            else {
                current = current->next;
            }
        }

        return head;
    }
};

