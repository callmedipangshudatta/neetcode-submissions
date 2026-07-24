class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto &p : mp){
            if(p.second > 1) return true;
        }
        return false;
    }
};