class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        int multiple = k;

        while(true)
        {
            bool found = false;

            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == multiple)
                {
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                return multiple;
            }

            multiple = multiple + k;
        }

        return -1;
    }
};