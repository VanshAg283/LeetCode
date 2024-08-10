class DisjointSet {
    vector<int> parent, size;
    int components;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            components--;
        }
    }

    void printDSU() {
        cout << "Index\tParent\tSize\n";
        for (int i = 0; i < parent.size(); ++i) {
            cout << i << "\t" << find(i) << "\t" << size[find(i)] << "\n";
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int totalVertices = (n + 1) * (n + 1);
        vector<vector<int>> graph(totalVertices);
        set<int> innerVertices;
        DisjointSet ds(totalVertices);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                int current = i * (n + 1) + j;
                innerVertices.insert(current);
            }
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                int current = i * (n + 1) + j;
                if (innerVertices.find(current) != innerVertices.end())
                    continue;

                if (j < n) {
                    int right = current + 1;
                    if (innerVertices.find(right) == innerVertices.end()) {
                        ds.unite(current, right);
                    }
                }

                if (i < n) {
                    int bottom = current + (n + 1);
                    if (innerVertices.find(bottom) == innerVertices.end()) {
                        ds.unite(current, bottom);
                    }
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = i * (n + 1) + j;
                char c = grid[i][j];
                if (c == '/') {
                    if (ds.find(idx + 1) == ds.find(idx + n + 1)) {
                        ans++;
                    } else {
                        ds.unite(idx + 1, idx + n + 1);
                    }
                }
                else if (c == '\\') {
                    if (ds.find(idx) == ds.find(idx + n + 2)) {
                        ans++;
                    } else {
                        ds.unite(idx, idx + n + 2);
                    }
                }
                else {
                    continue;
                }
            }
        }

        ds.printDSU();

        return ans;
    }
};