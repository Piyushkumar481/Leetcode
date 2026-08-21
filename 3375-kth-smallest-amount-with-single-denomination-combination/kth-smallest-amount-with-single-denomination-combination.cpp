class Solution {
public:

    long long gcd(long long a, long long b)
    {
        while(b != 0)
        {
            long long temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

    long long lcm(long long a, long long b)
    {
        return a / gcd(a, b) * b;
    }

    long long countAmount(long long x, vector<int>& coins)
    {
        long long ans = 0;

        int n = coins.size();

        for(int mask = 1; mask < (1 << n); mask++)
        {
            long long multiple = 1;
            int bits = 0;
            bool valid = true;

            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    bits++;

                    multiple = lcm(multiple, coins[i]);

                    if(multiple > x)
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if(!valid)
            {
                continue;
            }

            long long cnt = x / multiple;

            if(bits % 2 == 1)
            {
                ans += cnt;
            }
            else
            {
                ans -= cnt;
            }
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k)
    {
        long long low = 1;
        long long high = 1LL * coins[0] * k;

        for(int x : coins)
        {
            high = min(high, 1LL * x * k);
        }

        while(low < high)
        {
            long long mid = low + (high - low) / 2;

            if(countAmount(mid, coins) >= k)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

