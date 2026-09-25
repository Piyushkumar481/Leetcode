class Solution {
public:
    string s;
    int pos;

    set<string> parse() {
        set<string> result;
        vector<set<string>> parts;

        set<string> current;
        current.insert("");

        while(pos < s.size() && s[pos] != '}') {
            if(s[pos] == ',') {
                for(string a : current)
                    result.insert(a);

                current.clear();
                current.insert("");
                pos++;
            }
            else {
                set<string> next;

                if(s[pos] == '{') {
                    pos++;
                    next = parse();
                    pos++;
                }
                else {
                    next.insert(string(1, s[pos]));
                    pos++;
                }

                set<string> temp;

                for(string a : current) {
                    for(string b : next) {
                        temp.insert(a + b);
                    }
                }

                current = temp;
            }
        }

        for(string a : current)
            result.insert(a);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> result = parse();

        return vector<string>(result.begin(), result.end());
    }
};