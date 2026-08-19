class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, set<int>> mp;

        for(int i = 0; i < reservedSeats.size(); i++)
        {
            mp[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }

        int ans = (n - mp.size()) * 2;

        for(auto x : mp)
        {
            int row = x.first;
            set<int> seats = x.second;

            bool left = true;
            bool middle = true;
            bool right = true;

            for(int i = 2; i <= 5; i++)
            {
                if(seats.find(i) != seats.end())
                {
                    left = false;
                }
            }

            for(int i = 4; i <= 7; i++)
            {
                if(seats.find(i) != seats.end())
                {
                    middle = false;
                }
            }

            for(int i = 6; i <= 9; i++)
            {
                if(seats.find(i) != seats.end())
                {
                    right = false;
                }
            }

            if(left && right)
            {
                ans += 2;
            }
            else if(left || middle || right)
            {
                ans += 1;
            }
        }

        return ans;
    }
};