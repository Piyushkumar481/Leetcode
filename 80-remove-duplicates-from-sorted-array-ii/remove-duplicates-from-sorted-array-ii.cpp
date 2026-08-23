class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int index = 0;

        for(int x : nums)
        {
            if(index < 2 || x != nums[index - 2])
            {
                nums[index] = x;
                index++;
            }
        }

        return index;
    }
};