class Solution {
   public:
    bool isValid(string s) {
        stack<int> st;
        char top;
        for (char token : s) {
            if (token == '[' || token == '(' || token == '{') {
                st.push(token);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    top = st.top();
                    st.pop();
                    if ((token == ']' && top != '[') || (token == ')' && top != '(') ||
                        (token == '}' && top != '{')) {
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};
