
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = NULL;
        ListNode* current = head;

        while (current != NULL) {
            // Save the next node
            ListNode* nextNode = current->next;

            // Reverse the link
            current->next = previous;

            // Move previous forward
            previous = current;

            // Move current forward
            current = nextNode;
        }

        return previous;
    }
};

