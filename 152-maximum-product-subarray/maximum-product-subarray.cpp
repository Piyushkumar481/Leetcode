class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currProduct = 1;
        int minProduct = 1;
        int maxProduct = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            if(num == 0) {
                currProduct = 1;
                minProduct = 1;
                maxProduct = max(maxProduct, 0);
                continue;
            }

            int temp = currProduct;
            currProduct = max(num, max(temp * num, minProduct * num));
            minProduct = min(num, min(temp * num, minProduct * num));

            maxProduct = max(maxProduct, currProduct);
        }

        return maxProduct;
    }
};