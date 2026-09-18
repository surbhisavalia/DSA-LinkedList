class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;

        // Move first pointer n steps ahead
        for (int i = 0; i < n; i++) {
            first = first->next;
        }

        // If first becomes NULL, remove the first node
        if (first == NULL) {
            return head->next;
        }

        // Move both pointers until first reaches the end
        while (first->next != NULL) {
            first = first->next;
            second = second->next;
        }

        // second is now just before the node to remove
        second->next = second->next->next;

        return head;
    }
};