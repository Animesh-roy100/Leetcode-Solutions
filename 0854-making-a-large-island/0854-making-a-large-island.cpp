class Solution {
private:
vector<int> parent, size;

int findParent(int val) {
    if(val == parent[val]) return val;
    return parent[val] = findParent(parent[val]);
}

void UnionBySize(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);

    if(pu != pv) {
        if(size[pu] >= size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
}

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        
        parent.resize(n*n);
        for(int i=0; i<n*n; i++) parent[i] = i;
        size.resize(n*n, 1);

        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    for(auto& it: dir) {
                        int newX = i + it.first;
                        int newY = j + it.second;

                        if(newX<0 or newX>=n or newY<0 or newY>=n or grid[newX][newY] == 0) continue;

                        UnionBySize(i*n + j, newX*n + newY);   
                    }
                }
            }
        }


        int maxi=0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    set<int> s;
                    for(auto& it: dir) {
                        int newX = i + it.first;
                        int newY = j + it.second;

                        if(newX<0 or newX>=n or newY<0 or newY>=n or grid[newX][newY] == 0) continue;
                        s.insert(findParent(newX * n + newY));
                    }

                    int count=0;
                    for(auto& it: s) {
                        count += size[it];
                    }

                    maxi = max(maxi, count + 1); // extra 1 for flipped cell
                }
            }
        }
        
        // if no 0 present
        if(maxi == 0) {
            for(int i=0; i<n*n; i++) {
                maxi = max(maxi, size[i]);
            }
        }

        return maxi;
    }
};