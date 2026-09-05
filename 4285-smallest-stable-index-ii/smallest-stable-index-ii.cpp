class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> suffix(n);

        suffix[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = min((long long)nums[i], suffix[i + 1]);
        }

        long long mx = nums[0];

        for(int i = 0; i < n; i++) {
            mx = max(mx, (long long)nums[i]);

            if(mx - suffix[i] <= k)
                return i;
        }

        return -1;
    }
};