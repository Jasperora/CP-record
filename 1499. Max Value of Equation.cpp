// monotonic queue
class Solution1 {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ret = INT_MIN;
        // max {y_i + y_j + x_j - x_i}
        // fix j
        // max{x_j + y_j - x_i + y_i} for all x_j - x_i <= k
        // sliding window maximum
        // {-x_i + y_i, x_i}
        // monotonic decreasing queue (sorted by -x_i + y_i)
        deque<pair<int, int>> deq;
        for(const auto& point : points){
            int x_j = point[0], y_j = point[1];
            // pop front
            while(!deq.empty() && x_j - deq.front().second > k){
                deq.pop_front();
            }
            if(!deq.empty()){
                ret = max(ret, deq.front().first + x_j + y_j);
            }
            // pop back (the most important part)
            // since points are sorted by x
            // x_j ≥ any x in deque
            // if -x_j + y_j ≥ -x_i + y_i, then point i would never be chosen
            // since it is less than point j
            while(!deq.empty() && -x_j + y_j >= deq.back().first){
                deq.pop_back();
            }
            deq.push_back({-x_j + y_j, x_j});
        }
        return ret;
    }
};
// max heap
class Solution2 {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // max {y_i + y_j + x_j - x_i}
        // fix j
        // max{x_j + y_j - x_i + y_i} for all x_j - x_i <= k
        int ret = INT_MIN;
        // {-x_i + y_i, x_i}
        priority_queue<pair<int, int>> maxHeap;
        for(const auto& point : points){
            int x_j = point[0], y_j = point[1];
            // remove the infeasible points in heap
            // there might still be some infeasible points in the heap
            // but at least the top point is feasible
            while(!maxHeap.empty() && x_j - maxHeap.top().second > k){
                maxHeap.pop();
            }
            if(!maxHeap.empty()){
                ret = max(ret, x_j + y_j + maxHeap.top().first);
            }
            maxHeap.push({-x_j + y_j, x_j});
        }
        return ret;
    }
};