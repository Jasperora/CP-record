class Solution {
    public:
        int maxContainers(int n, int w, int maxWeight) {
            int cells = n*n;
            return min(n*n, (int)(maxWeight/w));
        }
    };