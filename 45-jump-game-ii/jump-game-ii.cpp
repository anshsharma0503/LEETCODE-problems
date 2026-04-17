class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int currend=0;
        int farthest=0;
        int jump=0;

        for(int i = 0; i < n ; i++){
            farthest = max(farthest , i + nums[i]);

            if(currend >= n - 1) return jump;

            if(i == currend){
                jump++;
                currend = farthest;
            }

            
        }

        return -1;
    }
};