class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char,int> mp;

        for(int i = 0; i < n ; i++){
            mp[s[i]] =i;
        }

        vector<int> res;

        int st =0 ,end=0;
        for(int i = 0; i < n ; i++){
            end = max(end , mp[s[i]]);

            if(i == end){
                res.push_back(end-st+ 1);
                st = i + 1;
            }
        }

        return res;
    }
};