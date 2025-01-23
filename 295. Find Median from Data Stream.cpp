class MedianFinder {
private:
    priority_queue<int> small_heap; // max heap
    priority_queue<int, vector<int>, greater<int> > large_heap; // min heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small_heap.push(num);
        if(small_heap.size()>large_heap.size()+1){
            large_heap.push(small_heap.top());
            small_heap.pop();
        }
        while(!small_heap.empty()&&!large_heap.empty()&&small_heap.top()>large_heap.top()){
            int M = small_heap.top();
            int m = large_heap.top();
            small_heap.pop();
            large_heap.pop();
            small_heap.push(m);
            large_heap.push(M);
        }
    }
    
    double findMedian() {
        if(small_heap.size()==large_heap.size()){
            return (double)(small_heap.top()+large_heap.top())/2;
        }else{
            if(small_heap.size()>large_heap.size()) return small_heap.top();
            else return large_heap.top();
        }
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */