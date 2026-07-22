class Solution {
public:

    int f(int i , int sum , vector<int>& nums, int tar){
        if(i == nums.size()) return sum == tar;

        int pos =  f(i + 1 , sum+ nums[i] ,nums , tar);
        int neg = f(i + 1 ,sum  -nums[i] ,  nums , tar);

        return pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0 ,0, nums , target);
    }
};