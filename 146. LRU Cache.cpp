class LRUCache {
private:
    map<int, pair<int, list<int>::iterator> > cache;
    list<int> order;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            order.erase(cache[key].second);
        }else if(cache.size()==capacity){
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */