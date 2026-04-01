class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) {
            return "\n";
        }
        string res = "";
        for (const string& s: strs) {
            res += s;
            res.push_back('\t');
        }
        if (!res.empty()) {
            res.pop_back();
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s == "\n") {
            return {};
        }
        vector<string> v;
        string temp = "";
        for (const char& c: s) {
            if (c != '\t') {
                temp.push_back(c);
            } else {
                v.push_back(temp);
                temp = "";
            }
        }
        v.push_back(temp);
        return v;
    }
};
