class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }

        vector<int> need(128,0);
        vector<int> window(128,0);

        //for counting the individual letters 
        for(char c: t){
            need[c]++;
        }

        int left = 0,have = 0,needCount = t.size();
        int start = 0;
        int minLen = INT_MAX;

        for(int right = 0;right<s.size();right++){
            window[s[right]]++;
            if(window[s[right]] <= need[s[right]]){
                have++;
            }
            while(have == needCount){
                if(right-left+1 < minLen){
                    minLen = right - left +1;
                    start = left;
                }
                window[s[left]]--;
                if(window[s[left]]<need[s[left]]){
                    have--;
                } 
                left++;
            }
        }
        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(start,minLen);
    }
};
