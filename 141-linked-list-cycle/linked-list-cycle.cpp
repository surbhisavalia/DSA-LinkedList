
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move 1 step
            fast = fast->next->next;    // Move 2 steps

            // If both meet, cycle exists
            if (slow == fast) {
                return true;
            }
        }

        // Fast reached the end, so no cycle
        return false;
    }
};
