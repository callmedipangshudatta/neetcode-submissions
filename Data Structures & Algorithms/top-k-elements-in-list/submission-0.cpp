class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        vector <pair<int,int>> vec;
        for(int x : nums){
            mp[x]++;
        }
        for(auto &it : mp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());

        vector<int> result;
        for(int i = 0;i<k;i++){
            result.push_back(vec[i].second);
        }
        return result;
    }
};
