class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int left = 0;
        for(int right = 0;right<nums.size();right++){
            int need = target - nums[right];
            if(mp.find(need)!=mp.end()){
                return {mp[need],right};
            }
            mp[nums[right]]=right;
        }
    }
};
