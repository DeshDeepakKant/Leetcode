class Solution {
public:
    int nearestExit(vector<vector<char>>& v, vector<int>& e) {
        int m = v.size();
        int n = v[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push({e[0], e[1]});
        vis[e[0]][e[1]] = 1;
        int ans = 0;

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int xx = q.size();
            for (int i = 0; i < xx; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                // Check if the current cell is an exit
                if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) && !(x == e[0] && y == e[1])) {
                    return ans;
                }

                // Check the four possible directions
                for (auto dir : directions) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && v[newX][newY] == '.' && !vis[newX][newY]) {
                        q.push({newX, newY});
                        vis[newX][newY] = 1;
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};
