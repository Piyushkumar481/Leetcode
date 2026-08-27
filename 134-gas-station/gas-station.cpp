class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int total = 0;
        int fuel = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++) {

            total += gas[i] - cost[i];

            fuel += gas[i] - cost[i];

            if(fuel < 0) {
                start = i + 1;
                fuel = 0;
            }
        }

        if(total >= 0)
            return start;

        return -1;
    }
};