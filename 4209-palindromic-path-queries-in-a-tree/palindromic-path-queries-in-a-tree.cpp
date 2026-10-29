class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n), parent(n);
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            parent[u] = p;
            tin[u] = timer++;

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer;
        };

        dfs(0, -1);

        int LOG = 17;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = (parent[i] == -1 ? i : parent[i]);

        for (int j = 1; j < LOG; j++)
            for (int i = 0; i < n; i++)
                up[j][i] = up[j - 1][up[j - 1][i]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        vector<int> bit(n + 2, 0);

        auto add = [&](int idx, int val) {
            for (int i = idx + 1; i <= n + 1; i += i & -i)
                bit[i] ^= val;
        };

        auto prefix = [&](int idx) {
            int res = 0;
            for (int i = idx + 1; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        };

        for (int u = 0; u < n; u++) {
            int val = 1 << (s[u] - 'a');
            add(tin[u], val);
            add(tout[u], val);
        }

        vector<bool> ans;

        for (string& q : queries) {
            string type, third;
            int u;
            stringstream ss(q);
            ss >> type >> u >> third;

            if (type == "update") {
                char c = third[0];
                int change = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));

                add(tin[u], change);
                add(tout[u], change);

                s[u] = c;
            } else {
                int v = stoi(third);
                int w = lca(u, v);

                int maskU = prefix(tin[u]);
                int maskV = prefix(tin[v]);
                int pathMask = maskU ^ maskV ^ (1 << (s[w] - 'a'));

                ans.push_back(__builtin_popcount((unsigned)pathMask) <= 1);
            }
        }

        return ans;
    }
};