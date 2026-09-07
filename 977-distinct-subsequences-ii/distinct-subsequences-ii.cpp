class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        vector<long long> last(26, 0);

        long long dp = 1;

        for(char c : s) {
            int x = c - 'a';

            long long old = dp;

            dp = (dp * 2 - last[x] + MOD) % MOD;

            last[x] = old;
        }

        return (dp - 1 + MOD) % MOD;
    }
};