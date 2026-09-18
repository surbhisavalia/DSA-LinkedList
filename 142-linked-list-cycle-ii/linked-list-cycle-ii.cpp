
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Find whether a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps

            if (slow == fast) {
                // Cycle found
                break;
            }
        }

        // No cycle
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // Step 2: Find the starting node of the cycle
        ListNode* current = head;

        while (current != slow) {
            current = current->next;
            slow = slow->next;
        }

        return current;
    }
};

