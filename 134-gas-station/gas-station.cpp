class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> net(n);

        int sum =0;
        for(int i = 0; i < n ;i++){
            net[i] = gas[i] - cost[i];
            sum += net[i];
        }


        int st_idx=0;
        int curr_sum =0;

        for(int i = 0; i< n; i++){
            curr_sum += net[i];

            if(curr_sum < 0){
                st_idx = i + 1;
                curr_sum =0;
            }
        }

        if(sum >= 0) return st_idx;
        return -1;
    }
};