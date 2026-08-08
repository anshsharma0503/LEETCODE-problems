class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin() , intervals.end() , [](auto a , auto b){
            return a[0] < b[0];
        });

        int st = intervals[0][0] , end = intervals[0][1];

        for(int i = 1; i < intervals.size() ; i++){
            if(intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            } else{
                res.push_back({st, end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({st, end});

        return res;
    }
};