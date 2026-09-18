
class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL) {
            return NULL;
        }

        // Map original node -> copied node
        unordered_map<Node*, Node*> copy;

        Node* current = head;

        // Create a copy of every node
        while (current != NULL) {
            copy[current] = new Node(current->val);
            current = current->next;
        }

        // Connect next and random pointers
        current = head;

        while (current != NULL) {

            copy[current]->next = copy[current->next];
            copy[current]->random = copy[current->random];

            current = current->next;
        }

        return copy[head];
    }
};

