class Solution {
public:

    struct job{
        int start,end,profit;
    };

    int findLast(vector<job>& jobs, int i) {
    int lo = 0, hi = i - 1;
    int ans = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (jobs[mid].end <= jobs[i].start) {
            ans = mid;
            lo = mid + 1;    
        } else {
            hi = mid - 1;
        }
    }

    return ans;
}

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<job> v;
        for(int i = 0;i < n; i++){
            v.push_back({startTime[i] , endTime[i] , profit[i]});
        }
        sort(v.begin() , v.end() , [](job a , job b){
            return a.end < b.end;
        });

        vector<int> dp(n , 0);
        dp[0]=v[0].profit;
        for(int i = 1 ; i < n ; i++){
            int notTake = dp[i - 1];

            int take = v[i].profit;
            int j = findLast(v , i);
            if(j != -1) take += dp[j];

            dp[i] = max(take , notTake);
        }

        return dp[n -1];
    }
};