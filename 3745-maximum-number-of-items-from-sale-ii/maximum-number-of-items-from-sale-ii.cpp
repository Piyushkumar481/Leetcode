class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
            cnt[i]--;
        }

        int minPrice = INT_MAX;
        vector<pair<int, int>> v;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            minPrice = min(minPrice, price);
            v.push_back({price, cnt[factor]});
        }

        sort(v.begin(), v.end());

        long long remaining = budget;
        long long bonus = 0;

        for (auto& [price, count] : v) {
            if (price >= 2LL * minPrice) {
                break;
            }

            long long take = min(1LL * count, remaining / price);

            bonus += take;
            remaining -= take * price;
        }

        return 2 * bonus + remaining / minPrice;
    }
};