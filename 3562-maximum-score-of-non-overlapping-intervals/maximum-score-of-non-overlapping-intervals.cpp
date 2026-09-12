class Solution {
public:
    struct Node {
        long long score;
        vector<int> indices;
    };

    bool better(Node a, Node b) {
        if(a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for(int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(a.begin(), a.end());

        vector<int> next(n);

        for(int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n;

            while(l < r) {
                int mid = l + (r - l) / 2;

                if(a[mid][0] > a[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            next[i] = l;
        }

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for(int i = n - 1; i >= 0; i--) {
            for(int k = 1; k <= 4; k++) {
                Node skip = dp[i + 1][k];

                Node take = dp[next[i]][k - 1];
                take.score += a[i][2];
                take.indices.push_back(a[i][3]);

                sort(take.indices.begin(), take.indices.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].indices;
    }
};