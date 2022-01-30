class Solution {
private:
    unordered_map<string, int> mp;

    void helper(string& s) {
        string str;
        for (auto& ch : s) {
            if (ch == ' ') {
                ++mp[str];
                str.clear();
            }
            else {
                str.push_back(ch);
            }
        }
        ++mp[str];
    }

public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        helper(s1);
        helper(s2);
        vector<string> ret;
        for (auto& tmp : mp) {
            if (tmp.second == 1) {
                ret.push_back(tmp.first);
            }
        }

        return ret;
    }
};
