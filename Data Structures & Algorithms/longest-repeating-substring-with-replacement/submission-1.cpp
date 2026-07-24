class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vec(26,0);
        int left = 0, maxFreq = 0,ans =0;
        for(int right = 0;right<s.size();right++){
            vec[s[right]-'A']++;
            maxFreq = max(maxFreq,vec[s[right]-'A']);
            while((right-left+1)-maxFreq>k){
                vec[s[left]-'A']--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
