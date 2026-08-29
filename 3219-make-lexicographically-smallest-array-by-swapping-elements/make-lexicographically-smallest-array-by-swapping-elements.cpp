class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> v;
        
        for(int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());
        
        int i = 0;
        
        while(i < v.size()) {
            int j = i;
            
            while(j + 1 < v.size() && v[j + 1].first - v[j].first <= limit) {
                j++;
            }
            
            vector<int> values;
            vector<int> indices;
            
            for(int x = i; x <= j; x++) {
                values.push_back(v[x].first);
                indices.push_back(v[x].second);
            }
            
            sort(indices.begin(), indices.end());
            
            for(int x = 0; x < values.size(); x++) {
                nums[indices[x]] = values[x];
            }
            
            i = j + 1;
        }
        
        return nums;
    }
};