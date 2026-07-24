class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0,ans = 0;
        for(int right = 0;right<s.length();right++){
            while(window.count(s[right])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
