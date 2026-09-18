
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        // Two separate lists
        ListNode* smaller = NULL;
        ListNode* greater = NULL;

        ListNode* smallEnd = NULL;
        ListNode* greaterEnd = NULL;

        ListNode* current = head;

        while (current != NULL) {

            if (current->val < x) {

                // Add node to smaller list
                if (smaller == NULL) {
                    smaller = current;
                    smallEnd = current;
                }
                else {
                    smallEnd->next = current;
                    smallEnd = current;
                }
            }
            else {

                // Add node to greater/equal list
                if (greater == NULL) {
                    greater = current;
                    greaterEnd = current;
                }
                else {
                    greaterEnd->next = current;
                    greaterEnd = current;
                }
            }

            current = current->next;
        }

        // If there are no smaller nodes
        if (smaller == NULL) {
            return greater;
        }

        // Connect the two lists
        smallEnd->next = greater;

        // Important: end the final list
        if (greaterEnd != NULL) {
            greaterEnd->next = NULL;
        }

        return smaller;
    }
};

