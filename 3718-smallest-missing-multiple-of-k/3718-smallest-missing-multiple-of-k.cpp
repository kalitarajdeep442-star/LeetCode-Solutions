class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> freq(101,0);
        for(int i=0; i<nums.size(); i++)
            freq[nums[i]] = 1;
        int ans = k;
        while(ans<=100){
            if(freq[ans] != 1)
                return ans;
            else
                ans += k;
        }
        return ((100/k)+1)*k;
    }
};