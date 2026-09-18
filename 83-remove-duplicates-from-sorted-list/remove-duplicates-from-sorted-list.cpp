
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* current = head;

        while (current != NULL && current->next != NULL) {

            // If two adjacent values are same
            if (current->val == current->next->val) {
                current->next = current->next->next;
            }
            else {
                // Move to next node
                current = current->next;
            }
        }

        return head;
    }
};

