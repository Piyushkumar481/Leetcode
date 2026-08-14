class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        int space = numRows;
        int starspace = 1;

        for (int i = 1; i <= numRows; i++) {
            vector<int> row;

            int x = 1;
            int num = i - 1;
            int den = 1;

            for (int b = 1; b <= starspace; b++) {
                row.push_back(x);

                x = (x * num) / den;
                num--;
                den++;
            }

            ans.push_back(row);

            space--;
            starspace++;
        }

        return ans;
    }
};