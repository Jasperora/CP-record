class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0, r = n-1;
        pair<int, int> tl(l, l), tr(l, r), bl(r, l), br(r, r);
        while(tl.second<tr.second){
            for(int i = 0; i < r-l; ++i){
                int tmp = matrix[tl.first][tl.second];
                matrix[tl.first][tl.second++] = matrix[bl.first][bl.second];
                matrix[bl.first--][bl.second] = matrix[br.first][br.second];
                matrix[br.first][br.second--] = matrix[tr.first][tr.second];
                matrix[tr.first++][tr.second] = tmp;
            }
            ++l;
            --r;
            tl.first = tl.second = tr.first = bl.second = l;
            tr.second = bl.first = br.first = br.second = r;
        }
    }
};
