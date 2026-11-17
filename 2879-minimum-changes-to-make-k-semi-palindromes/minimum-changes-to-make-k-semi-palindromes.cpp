class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int groups = len / d;
                    int changes = 0;

                    for (int rem = 0; rem < d; rem++) {
                        for (int p = 0; p < groups / 2; p++) {
                            int i = l + rem + p * d;
                            int j = l + rem + (groups - 1 - p) * d;

                            if (s[i] != s[j]) {
                                changes++;
                            }
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int i = 2 * parts; i <= n; i++) {
                for (int j = 2 * (parts - 1); j <= i - 2; j++) {
                    if (dp[j][parts - 1] == INF) continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[j][parts - 1] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};