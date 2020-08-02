class MyHashSet {
public:
    bool* container;
    /** Initialize your data structure here. */
    MyHashSet() {
        container = new bool[1000001];
        for (int i = 0; i < 1000001; i++) {
            container[i] = false;
        }
    }
    
    void add(int key) {
        container[key] = true;
    }
    
    void remove(int key) {
        container[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return container[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
