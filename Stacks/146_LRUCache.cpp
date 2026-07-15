class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int capacity;
    
    
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity= capacity;
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insert(Node* node) {
        Node* prevMRU = tail->prev;
        prevMRU->next = node;
        node->prev = prevMRU;
        node->next = tail;
        tail->prev = node;
    }

    int get(int key) {
        
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* node = mp[key];
        
        remove(node);
        insert(node);
        return node->value;
        
    }

    void put(int key, int value) {
        
        if (mp.find(key) != mp.end()) {
            Node* node= mp[key];
            node->value = value;
            
            remove(node);
            insert(node);
        } 
        
        else {
            if (capacity ==mp.size()) {
                Node* lru = head->next;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            
            Node* node = new Node(key, value);
            insert(node);
            mp[key] = node;
        }
    }
};
