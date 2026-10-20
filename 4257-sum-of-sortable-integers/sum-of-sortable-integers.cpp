class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int k = 1; k <= n; k++) {
            if(n % k != 0)
                continue;

            bool ok = true;
            vector<int> result;

            for(int start = 0; start < n; start += k) {
                vector<int> block(nums.begin() + start, nums.begin() + start + k);

                int descents = 0;
                int pos = 0;

                for(int i = 0; i < k; i++) {
                    int next = (i + 1) % k;

                    if(block[i] > block[next]) {
                        descents++;
                        pos = next;
                    }
                }

                if(descents > 1) {
                    ok = false;
                    break;
                }

                for(int i = 0; i < k; i++)
                    result.push_back(block[(pos + i) % k]);
            }

            if(ok && is_sorted(result.begin(), result.end()))
                ans += k;
        }

        return ans;
    }
};