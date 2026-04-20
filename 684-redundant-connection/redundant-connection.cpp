class DSU{
public:
    vector<int> par,size;

    DSU(int n){
        par.resize(n +1);
        size.resize(n +1, 1);

        for(int i = 0; i < n ; i++){
            par[i] = i;
        }
    }

    int find(int x){
        if(par[x] == x) return x;

        return par[x] = find(par[x]);
    }

    bool unite(int u , int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return false;

        if(size[pu] < size[pv]){
            par[pu] =pv;
            size[pv] += size[pu];
        } else{
            par[pv] = pu;
            size[pu] += size[pv];
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n);

        for(auto e : edges){
            int u= e[0];
            int v = e[1];

            if(!dsu.unite(u , v)){
                return {u , v};
            }
        }

        return {};
    }
};