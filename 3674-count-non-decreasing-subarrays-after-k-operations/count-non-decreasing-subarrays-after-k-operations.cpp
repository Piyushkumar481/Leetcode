class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nxt(n + 1, n);
        vector<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i]) {
                st.pop_back();
            }
            if (!st.empty()) nxt[i] = st.back();
            st.push_back(i);
        }

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        int LOG = 18;

        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> sum(LOG, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            sum[0][i] = 1LL * nums[i] * (nxt[i] - i - 1)
                      - (pref[nxt[i]] - pref[i + 1]);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i <= n; i++) {
                int mid = up[j - 1][i];
                up[j][i] = up[j - 1][mid];
                sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
            }
        }

        auto getCost = [&](int l, int r) {
            long long cost = 0;
            int cur = l;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][cur] <= r) {
                    cost += sum[j][cur];
                    cur = up[j][cur];
                }
            }

            cost += 1LL * nums[cur] * (r - cur)
                  - (pref[r + 1] - pref[cur + 1]);

            return cost;
        };

        long long ans = 0;

        for (int l = 0; l < n; l++) {
            int low = l, high = n - 1;
            int best = l - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (getCost(l, mid) <= k) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            ans += best - l + 1;
        }

        return ans;
    }
};