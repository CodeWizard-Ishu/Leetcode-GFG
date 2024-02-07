class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        vector<string> str(s.size() + 1, "");
        string res;

        for (char c : s)
            mp[c]++;

        for (auto& it : mp) {
            int n = it.second;
            char c = it.first;
            str[n].append(n, c);
        }

        for (int i = s.size(); i > 0; i--) {
            if (!str[i].empty())
                res.append(str[i]);
        }
        return res;
    }
};