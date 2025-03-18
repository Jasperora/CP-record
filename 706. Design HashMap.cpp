class MyHashMap {
    public:
        vector<pair<int, int>> vp;
        MyHashMap() {
            
        }
        
        void put(int key, int value) {
            bool has = false;
            for(auto& p : vp){
                if(p.first==key){
                    has = true;
                    p.second = value;
                    break;
                }
            }
            if(!has){
                vp.push_back({key, value});
            }
        }
        
        int get(int key) {
            for(auto& p : vp){
                if(p.first==key) return p.second;
            }
            return -1;
        }
        
        void remove(int key) {
            for(int i = 0; i < vp.size(); ++i){
                if(vp[i].first==key){
                    vp.erase(vp.begin()+i);
                    break;
                }
            }
        }
    };
    
    /**
     * Your MyHashMap object will be instantiated and called as such:
     * MyHashMap* obj = new MyHashMap();
     * obj->put(key,value);
     * int param_2 = obj->get(key);
     * obj->remove(key);
     */