class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int count[51] = {0};

        for(int i = 0; i <= nums.size() - k; i++)
        {
            bool present[51] = {false};

            for(int j = i; j < i + k; j++)
            {
                present[nums[j]] = true;
            }

            for(int j = 0; j <= 50; j++)
            {
                if(present[j])
                {
                    count[j]++;
                }
            }
        }

        for(int i = 50; i >= 0; i--)
        {
            if(count[i] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};