class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int valid_count = 0;
        for(int i=0; i<n; i++){
            int x=0, y=0;
            for(int j=i; j<n; j++){
                if(nums[j]&1)   y++;
                else   x++;
                if(y>0 && 1LL*x*b <= 1LL*y*a)
                    valid_count++;
            }
        }
        return valid_count;
    }
};