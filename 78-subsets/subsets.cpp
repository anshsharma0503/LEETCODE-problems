class Solution {
public:

    vector<vector<int>> ans;

    void f(int i , vector<int>& a , vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(a);
            return;
        }

        a.push_back(nums[i]);
        f(i + 1 , a , nums);
        a.pop_back();

        f(i + 1 , a , nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;

         f(0 , a ,  nums);

         return ans;
    }
};