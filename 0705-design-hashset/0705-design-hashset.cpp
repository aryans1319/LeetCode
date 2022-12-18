class MyHashSet {
    int numBuckets;
    vector<vector<int>> buckets;
private:
    int findHash(int key){
        return key % numBuckets;
    }    
public:
    MyHashSet() {
        numBuckets = 15000;
        buckets = vector<vector<int>>(numBuckets, vector<int>{});
    }
    void add(int key) {
        int searchKey = findHash(key);
        if(find(buckets[searchKey].begin(), buckets[searchKey].end(), key) == buckets[searchKey].end()){
            buckets[searchKey].push_back(key);
        }
    }
    
    void remove(int key) {
        int searchKey = findHash(key);
        auto it = find(buckets[searchKey].begin(), buckets[searchKey].end(), key);
        if(it != buckets[searchKey].end()){
            buckets[searchKey].erase(it);
        }
    }
    
    bool contains(int key) {
        int searchKey = findHash(key);
        if(find(buckets[searchKey].begin(), buckets[searchKey].end(), key) == buckets[searchKey].end()){
            return false;
        }
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */