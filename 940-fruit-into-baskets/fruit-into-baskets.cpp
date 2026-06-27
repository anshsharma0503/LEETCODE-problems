class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int , int> mp;
        int l = 0;
        int res = 0;

        for(int r = 0 ; r < fruits.size() ; r++){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            res = max(res , r - l + 1);
        }

        return res;

    }
};