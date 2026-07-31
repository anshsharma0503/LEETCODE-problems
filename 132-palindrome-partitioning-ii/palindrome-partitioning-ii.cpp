class Solution {
public:

    vector<int> dp;

    bool isPalindrome(int l, int r, string &s){

        while(l < r){

            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    int f(int i, string &s){

        int n = s.size();

        if(i == n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for(int j = i; j < n; j++){

            if(isPalindrome(i,j,s)){

                ans = min(ans,1 + f(j+1,s));
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {

        int n = s.size();

        dp.resize(n,-1);

        return f(0,s) - 1;
    }
};