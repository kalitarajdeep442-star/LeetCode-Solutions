class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int> freq(26,0);
        for(char c : s)     
            freq[c-'a']++;
        string prefix;
        for(int i=0; i<n; i++){
            int x = target[i]-'a';
            if(freq[x] == 0)
                break;
            freq[x]--;
            prefix += target[i];
        }
        if((int)prefix.size() < n){
            int i = prefix.size();
            int x = target[i]-'a';
            for(int c=x+1; c<26; c++){
                if(freq[c] == 0)
                    continue;
                string ans=prefix;
                ans += char('a'+c);
                freq[c]--;
                for(int ch=0; ch<26; ch++){
                    ans.append(freq[ch],char('a'+ch));
                }
                return ans;
            }
        }
        for(int i=prefix.size()-1; i>=0; i--){
            freq[prefix[i]-'a']++;
            prefix.pop_back();
            int x = target[i]-'a';
            for(int c=x+1; c<26; c++){
                if(freq[c] == 0)
                    continue;
                string ans=prefix;
                ans += char('a'+c);
                freq[c]--;
                for(int ch=0; ch<26; ch++){
                    ans.append(freq[ch],char('a'+ch));
                }
                return ans;
            }
        }
        return "";
    }
};