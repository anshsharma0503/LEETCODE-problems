class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;

        for(int top = 0; top < row ; top++){
            vector<int> colsum(col , 0);
            for(int bottom = top ; bottom < row ; bottom++){
                for(int c = 0; c < col ; c++){
                    colsum[c] += matrix[bottom][c];
                }

                unordered_map<int , int> freq;
                freq[0] = 1;
                vector<int> pre(col);
                pre[0] = colsum[0];
                for(int i = 1 ; i < col ; i++) pre[i] = pre[i - 1] + colsum[i];

                for(int i = 0 ; i< col ; i++){
                    if(freq.find(pre[i] - target) != freq.end()) ans += freq[pre[i] - target];
                    freq[pre[i]]++;
                }
            }
        }

        return ans;
    }
};