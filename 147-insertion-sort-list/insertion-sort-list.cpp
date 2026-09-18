
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* sorted = NULL;
        ListNode* current = head;

        while (current != NULL) {
            ListNode* nextNode = current->next;

            // Insert current node into sorted list
            if (sorted == NULL || current->val < sorted->val) {
                current->next = sorted;
                sorted = current;
            } else {
                ListNode* position = sorted;

                // Find the correct position
                while (position->next != NULL &&
                       position->next->val <= current->val) {
                    position = position->next;
                }

                // Insert current node
                current->next = position->next;
                position->next = current;
            }

            current = nextNode;
        }

        return sorted;
    }
};

