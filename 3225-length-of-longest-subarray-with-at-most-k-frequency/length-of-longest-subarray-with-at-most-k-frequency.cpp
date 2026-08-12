class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++)
        {
            freq[nums[right]]++;

            while(freq[nums[right]] > k)
            {
                freq[nums[left]]--;
                left++;
            }

            int length = right - left + 1;

            if(length > ans)
            {
                ans = length;
            }
        }

        return ans;
    }
};