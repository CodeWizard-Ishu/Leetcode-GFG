class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto i : arr)
            mp[i]++;

            vector<int> v;
            int count = 0;
            for(auto i : mp)
                v.push_back(i.second);

            sort(v.begin(), v.end());
            for(int i = 0; i<v.size(); i++)
            {
                if(k > v[i])
                {
                    k = k- v[i];
                    v[i] = 0;
                }
                else
                {
                    v[i] = v[i] - k;
                    k = 0;
                }
                if(v[i] != 0)
                    count++;
            }

            return count;
    }
};