#include <bits/stdc++.h>
class DisjointSet
{
// private:
    vector<int> rank,parent,size;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = 1;
            size[i] = 1;
        }
    }
    int findPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findPar[parent[node]];
    }
    void uninByRank(int u,int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v) {
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
            
        } else if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }
    void uninBySize(int u,int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v) {
            return;
        }
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_u] += size[ulp_v];
        } else {
             parent[ulp_v] = ulp_u;
            size[ulp_v] += size[ulp_u];
        }
    }
};

DisjointSet::DisjointSet(/* args */)
{
}

DisjointSet::~DisjointSet()
{
}
