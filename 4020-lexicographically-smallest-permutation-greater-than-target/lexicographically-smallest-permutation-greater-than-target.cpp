class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for(char c : s)
            cnt[c - 'a']++;

        for(int i = n - 1; i >= 0; i--) {
            vector<int> temp = cnt;
            string ans = "";

            bool possible = true;

            for(int j = 0; j < i; j++) {
                if(temp[target[j] - 'a'] == 0) {
                    possible = false;
                    break;
                }

                temp[target[j] - 'a']--;
                ans += target[j];
            }

            if(!possible)
                continue;

            for(int c = target[i] - 'a' + 1; c < 26; c++) {
                if(temp[c] > 0) {
                    ans += char('a' + c);
                    temp[c]--;

                    for(int x = 0; x < 26; x++) {
                        while(temp[x] > 0) {
                            ans += char('a' + x);
                            temp[x]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};