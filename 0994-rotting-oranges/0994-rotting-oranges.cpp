
class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int row, int col, int n, int m) {
        return row >= 0 && row < n &&
               col >= 0 && col < m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } 
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (!q.empty() && fresh > 0) {
            int s = q.size();
            time++;

            while (s--) {
                auto p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                for (int k = 0; k < 4; k++) {
                    int row = r + x[k];
                    int col = c + y[k];

                    if (valid(row, col, n, m) &&
                        grid[row][col] == 1) {
                        q.push({row, col});
                        grid[row][col] = 2;
                        fresh--;
                    }
                }
            }
        }

        return fresh > 0 ? -1 : time;
    }
};
