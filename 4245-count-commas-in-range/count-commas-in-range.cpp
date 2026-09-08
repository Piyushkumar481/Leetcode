class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        for(int i = 1000; i <= n; i++) {
            ans++;
        }

        return ans;
    }
};