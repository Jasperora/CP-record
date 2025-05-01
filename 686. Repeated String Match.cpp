class Solution {
    public:
    int repeatedStringMatch(string a, string b) {
        int times = ceil((float)b.size() / a.size());
        string repeat_a = "";
        for(int i = 0; i < times; ++i)
        repeat_a += a;
        if(repeat_a.find(b) != string::npos)
        return times;
        // at most times + 1, or b will never be a substring of repeated_a
        // because b is like (suffix of a + several a + prefix of a)
        repeat_a += a;
        if(repeat_a.find(b) != string::npos)
        return times + 1;
        return -1;
    }
};