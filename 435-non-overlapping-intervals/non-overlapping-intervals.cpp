class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        int cnt =0,lastend = -1e9;
        for(int i = 0; i < intervals.size() ; i++){
            if(intervals[i][0] >= lastend) {
                cnt++;
                lastend = intervals[i][1];
            }
        }

        if(cnt == 0) return 0;

        return intervals.size() - cnt;
    }
};