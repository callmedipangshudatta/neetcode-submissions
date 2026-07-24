class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxLong = 0;
        for(int x:st){
            if(st.find(x-1)==st.end()){
                int currNum = x;
                int currL = 1;
                while(st.find(currNum+1)!=st.end()){
                    currNum ++;
                    currL++;
                }
                maxLong = max(maxLong,currL);
            }
        }
        return maxLong;
    }
};
