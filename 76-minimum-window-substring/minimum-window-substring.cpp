class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> freq;

        for(char c : t)
            freq[c]++;

        int cnt = t.size();

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;

        for(int right = 0; right < s.size(); right++) {

            if(freq[s[right]] > 0)
                cnt--;

            freq[s[right]]--;

            while(cnt == 0) {

                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if(freq[s[left]] > 0)
                    cnt++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};