class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int x=0;x<nums.size();x++){
            int need = target - nums[x];
            if(mp.count(need)){
                return {mp[need],x};
            }
            mp[nums[x]] = x;
        }
        return {};
    }
};
