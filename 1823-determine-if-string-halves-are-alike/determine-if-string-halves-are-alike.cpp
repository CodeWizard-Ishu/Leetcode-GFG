class Solution {
public:
    bool halvesAreAlike(string s) {
        int temp = 0;
        for(int i = 0; i<s.size(); i++)
        {
            s[i] = tolower(s[i]);
            if(i<s.size()/2)
            {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                    temp++;
            }
            else
            {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                    temp--;
            }
        }
        return temp==0;
    }
};