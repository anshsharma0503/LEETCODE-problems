class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int> freq(26 , 0);

        for(int ch : s){
            freq[ch - 'a']++;
        }

        for(int ch : t){
            freq[ch - 'a']--;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] != 0) return false;
        }

        return true;
    }
};