class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a  =edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];

        if(a == b) return a;
        if(a== c) return a;
        if(a==d) return a;

        if(b==c) return b;
        if(b==d) return b;

        if(c == d) return c;

        return -1;
    }
};