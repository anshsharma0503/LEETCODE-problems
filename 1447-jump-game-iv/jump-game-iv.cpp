class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp;
        for(int i = 0 ; i < n ; i ++)
            mp[arr[i]].push_back(i);

        vector<int> vis(n , 1);
        queue<int> q;
        q.push(0);
        vis[0] = 0;
        int jumps =0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int i = q.front();
                q.pop();

                if(i == n - 1) 
                    return jumps;

                if(i + 1 < n && vis[i + 1]){
                    q.push(i + 1);
                    vis[i + 1] =0;
                }

                if(i - 1 >=0 && vis[i - 1]){
                    q.push(i -1);
                    vis[i - 1] =0;
                }  

                for(auto x : mp[arr[i]]){
                    if(vis[x]){
                        vis[x] = 0;
                        q.push(x);
                    }
                } 

                mp[arr[i]].clear();           
            }

            jumps++;
        }           

        return -1;
    }
};