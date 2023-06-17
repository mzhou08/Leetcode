typedef struct DLLNode {
    int key;
    int value;
    struct DLLNode* prev;
    struct DLLNode* next;
} DLLNode;


typedef struct {
    int size;
    int capacity;
    DLLNode* head;
    DLLNode* tail;
    unordered_map<int, DLLNode*> mems;
} DLL;


void removeNode(DLL* dll, DLLNode* node) {
    if (node->prev == NULL && node->next == NULL) {
        // single entry dll
        dll->head = NULL;
        dll->tail = NULL;
    } else if (node->prev == NULL) {
        // at head
        dll->head = node->next;
        node->next->prev = NULL;
    } else if (node->next == NULL) {
        // at tail
        dll->tail = node->prev;
        node->prev->next = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    dll->mems.erase(node->key);

    delete node;

    dll->size--;
}

void insertHead(DLL* dll, int key, int value) {
    // insert head
    DLLNode* curr_head = dll->head;

    // note: new is generally preferred, as you don't need to cast
    // malloc/free => new/delete
    DLLNode* node = new DLLNode;
    node->key = key;
    node->value = value;
    node->next = curr_head;
    node->prev = NULL;

    if (curr_head == NULL) {
        dll->tail = node;
    } else {
        curr_head->prev = node;
    }

    dll->head = node;
    dll->size++;

    dll->mems[key] = node;
}

void printDLL(DLL* dll) {
    for (DLLNode *c = dll->head; c != NULL; c = c->next) {
        cout << c->key << " " << c->value << "\n";
    }
}

class LRUCache {
public:
    DLL* cache;

    LRUCache(int capacity) {
        cache = new DLL;

        cache->size = 0;
        cache->capacity = capacity;
        cache->head = NULL;
        cache->tail = NULL;
        cache->mems = unordered_map<int, DLLNode*>();   
    }
    
    int get(int key) {
        if (cache->mems.find(key) != cache->mems.end()) {
            DLLNode* c = cache->mems[key];
            int val = c->value;
            
            removeNode(cache, c);
            insertHead(cache, key, val);

            return val;
        }

        return -1;
    }
    
    void put(int key, int value) {

        if (cache->mems.find(key) != cache->mems.end()) {
            DLLNode* c = cache->mems[key];
            
            removeNode(cache, c);
            insertHead(cache, key, value);

            return;
        }

        if (cache->size == cache->capacity) {
            removeNode(cache, cache->tail);
        }

        insertHead(cache, key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */