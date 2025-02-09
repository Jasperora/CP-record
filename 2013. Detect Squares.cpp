class DetectSquares {
private:
    map<vector<int>, int> m;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        ++m[point];
    }
    
    int count(vector<int> point) {
        int ret = 0;
        int x = point[0], y = point[1];
        for(auto& p : m){
            int px = p.first[0], py = p.first[1];
            if(abs(x-px)==abs(y-py) && px!=x){
                if(m.count({px, y}) && m.count({x, py})){
                    ret += m[{px, y}] * m[{x, py}] * m[{px, py}];
                }
            }
        }
        return ret;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */