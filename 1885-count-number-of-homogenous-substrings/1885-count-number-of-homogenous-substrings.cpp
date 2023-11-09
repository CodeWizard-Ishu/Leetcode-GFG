class Solution {
public:
    int countHomogenous(string s) {
        int result = 0, curr = 0, count = 0, mod = 1e9+7;
        for(int i : s)
        {
            count = i == curr ? count+1 : 1;
            curr = i;
            result = (result + count) % mod;
        }
        return result;
    }
};