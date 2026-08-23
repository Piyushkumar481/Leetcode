class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        int leftQ = 0;
        int rightQ = 0;

        int diff = 0;

        for(int i = 0; i < n / 2; i++)
        {
            if(num[i] == '?')
                leftQ++;
            else
                diff += num[i] - '0';
        }

        for(int i = n / 2; i < n; i++)
        {
            if(num[i] == '?')
                rightQ++;
            else
                diff -= num[i] - '0';
        }

        if(leftQ == rightQ)
        {
            return diff != 0;
        }

        int qDiff = abs(leftQ - rightQ);

        if(qDiff % 2 == 1)
        {
            return true;
        }

        if(leftQ > rightQ)
        {
            diff += 9 * (qDiff / 2);
        }
        else
        {
            diff -= 9 * (qDiff / 2);
        }

        return diff != 0;
    }
};