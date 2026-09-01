class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastOccurance(26);
        vector<int> freq(26,0);
        for(int i=0; i<s.size(); i++){
            lastOccurance[s[i]-'a'] = i;
            freq[s[i]-'a'] = 0;
        }
        stack<char> st; 
        for(int i=0; i<s.size(); i++){
            if(freq[s[i]-'a'] == 1)
                continue;
            while(!st.empty() && s[i]<st.top() && i<lastOccurance[st.top()-'a']){
                freq[st.top()-'a'] = 0;
                st.pop();
            }
            freq[s[i]-'a'] = 1;
            st.push(s[i]);
        }
        string res;
        while(!st.empty()){
            res = st.top()+res;
            st.pop();
        }
        return res;
    }
};