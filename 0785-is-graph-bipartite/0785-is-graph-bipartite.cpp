
class Solution {
public:

    bool dfs(vector<vector<int>>& a, int node, int c,
             vector<int>& colors) {

        colors[node] = c;

        for(int j = 0; j < a[node].size(); j++) {

            int neigh = a[node][j];

            if(colors[neigh] == c) {
                return false;
            }

            if(colors[neigh] == -1) {
                if(!dfs(a, neigh, 1-c, colors)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& a) {

        int n = a.size();

        vector<int> colors(n, -1);

        for(int i = 0; i < n; i++) {

            if(colors[i] == -1) {

                if(!dfs(a, i, 0, colors)) {
                    return false;
                }
            }
        }

        return true;
    }
};
