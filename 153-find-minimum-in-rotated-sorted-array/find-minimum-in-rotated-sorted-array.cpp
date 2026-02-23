class Solution {
public:
    int findMin(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int i = 0 ; i < nums.size() ; i++){
                cnt++;
            }
        }

        int st=0,end=nums.size()-1;
        int minimum=INT_MAX;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[st]<=nums[mid]){
                minimum=min(minimum,nums[st]);
                st=mid+1;
            }
            else{
                minimum=min(minimum,nums[mid]);
                end=mid-1;
            }
        }
        return minimum;
    }
};