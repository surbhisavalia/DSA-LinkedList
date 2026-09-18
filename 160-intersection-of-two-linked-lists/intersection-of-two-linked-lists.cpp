
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* first = headA;
        ListNode* second = headB;

        while (first != second) {
            // If first reaches end, move it to headB
            if (first == NULL)
                first = headB;
            else
                first = first->next;

            // If second reaches end, move it to headA
            if (second == NULL)
                second = headA;
            else
                second = second->next;
        }

        // Intersection node or NULL
        return first;
    }
};

