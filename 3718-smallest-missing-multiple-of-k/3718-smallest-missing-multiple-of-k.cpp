class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%k==0)
                mp[nums[i]]++;
        }
        int ans=k;
        while(1){
            if(mp.find(ans) != mp.end())
                ans+=k;
            else
                return ans;
        }
    }
};