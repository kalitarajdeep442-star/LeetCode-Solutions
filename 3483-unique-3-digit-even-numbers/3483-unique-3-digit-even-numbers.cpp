class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10);
        for(int i=0; i<digits.size(); i++){
            freq[digits[i]]++;
        }
        int cnt = 0;
        for(int i=100; i<=998; i+=2){
            string s = to_string(i);
            int a = s[0]-'0', b = s[1]-'0', c = s[2]-'0'; 
            int flag=0;
            if(freq[a]>0)   flag++; 
            freq[a]--;
            if(freq[b]>0)   flag++;
            freq[b]--;
            if(freq[c]>0)   flag++;
            freq[c]--;
            if(flag==3) cnt++;
            freq[a]++, freq[b]++, freq[c]++;
        }
        return cnt;
    }
};