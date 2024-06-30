class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v, int& ct) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) {
            ct++;
            return;
        } 
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n);
        DisjointSet bob(n);
        sort(edges.rbegin(), edges.rend());
        int ct = 0;
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][0] == 1) {
                alice.unionByRank(edges[i][1], edges[i][2], ct);
            } else if (edges[i][0] == 2) {
                bob.unionByRank(edges[i][1], edges[i][2], ct);
            } else {
                alice.unionByRank(edges[i][1], edges[i][2], ct);
                bob.unionByRank(edges[i][1], edges[i][2], ct);
            }
        }
        int par1 = alice.findUPar(1);
        int par2 = bob.findUPar(1);
        for (int i = 2; i <= n; ++i) {
            if (alice.findUPar(i) != par1) {
                return -1;
            } else if (bob.findUPar(i) != par2) {
                return -1;
            }
        }
        return ct;
    }
};