class Solution {
public:
    int nearestExit(vector<vector<char>>& v, vector<int>& e) {
        int m = v.size();
        int n = v[0].size();
        queue<pair<int, int>> q;
        // vector<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push({e[0], e[1]});
        int ans = 0;
        int directions[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Use an array for directions

        while (!q.empty()) {
            int xx = q.size();
            for (int i = 0; i < xx; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                vis[x][y] = 1;
                if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) &&
                    !(x == e[0] && y == e[1])) {
                    return ans;
                }
                // if (x + 1 >= 0 && x + 1 < m && y >= 0 && y < n &&
                //     v[x + 1][y] == '.' && !vis[x + 1][y]) {
                //     q.push({x + 1, y});
                // }
                // if (x - 1 >= 0 && x - 1 < m && y >= 0 && y < n &&
                //     v[x - 1][y] == '.' && !vis[x - 1][y]) {
                //     q.push({x - 1, y});
                // }
                // if (x >= 0 && x < m && y + 1 >= 0 && y + 1 < n &&
                //     v[x][y + 1] == '.' && !vis[x][y + 1]) {
                //     q.push({x, y + 1});
                // }
                // if (x >= 0 && x < m && y - 1 >= 0 && y - 1 < n &&
                //     v[x][y - 1] == '.' && !vis[x][y - 1]) {
                //     q.push({x, y - 1});
                // }

                // for (auto dir : directions) {
                //     int newX = x + dir[0];
                //     int newY = y + dir[1];
                //     if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                //         v[newX][newY] == '.' && !vis[newX][newY]) {
                //         q.push({newX, newY});
                //         vis[newX][newY] = 1; // Mark as visited when
                //         enqueuing
                //     }
                // }

                if (x + 1 < m && v[x + 1][y] == '.' && !vis[x + 1][y]) {
                    q.push({x + 1, y});
                    vis[x + 1][y] = 1;
                }
                if (x - 1 >= 0 && v[x - 1][y] == '.' && !vis[x - 1][y]) {
                    q.push({x - 1, y});
                    vis[x - 1][y] = 1;
                }
                if (y + 1 < n && v[x][y + 1] == '.' && !vis[x][y + 1]) {
                    q.push({x, y + 1});
                    vis[x][y + 1] = 1;
                }
                if (y - 1 >= 0 && v[x][y - 1] == '.' && !vis[x][y - 1]) {
                    q.push({x, y - 1});
                    vis[x][y - 1] = 1;
                }
            }
            cout << ans;
            ans++;
        }

        return -1;
    }
};