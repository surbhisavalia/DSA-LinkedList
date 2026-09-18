
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right) {
            return head;
        }

        ListNode* current = head;
        ListNode* before = NULL;

        // Move current to the left position
        for (int i = 1; i < left; i++) {
            before = current;
            current = current->next;
        }

        // Save the first node of the part being reversed
        ListNode* first = current;

        ListNode* previous = NULL;

        // Reverse from left to right
        for (int i = left; i <= right; i++) {
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        // Connect the reversed part to the beginning
        if (before == NULL) {
            head = previous;
        }
        else {
            before->next = previous;
        }

        // Connect the end of reversed part to remaining list
        first->next = current;

        return head;
    }
};

