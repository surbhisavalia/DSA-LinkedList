
class LRUCache {
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;

    // Stores key -> node address
    unordered_map<int, Node*> cache;

    // Doubly linked list
    Node* head;   // Most recently used
    Node* tail;   // Least recently used

    // Add node at the front
    void addFront(Node* current) {
        current->next = head->next;
        current->prev = head;

        head->next->prev = current;
        head->next = current;
    }

    // Remove a node
    void removeNode(Node* current) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        // Dummy head and tail
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // Key not found
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* current = cache[key];

        // This key is recently used, so move it to front
        removeNode(current);
        addFront(current);

        return current->value;
    }

    void put(int key, int value) {
        // If key already exists
        if (cache.find(key) != cache.end()) {
            Node* current = cache[key];

            current->value = value;

            // Move it to front
            removeNode(current);
            addFront(current);

            return;
        }

        // Create new node
        Node* current = new Node(key, value);

        cache[key] = current;
        addFront(current);

        // If capacity is exceeded
        if (cache.size() > capacity) {
            Node* leastUsed = tail->prev;

            cache.erase(leastUsed->key);
            removeNode(leastUsed);

            delete leastUsed;
        }
    }
};

