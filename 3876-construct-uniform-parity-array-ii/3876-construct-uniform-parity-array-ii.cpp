class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int odd=0, even=0;
        int smallest_odd = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums1[i]&1){
                odd++;
                smallest_odd = min(smallest_odd, nums1[i]);
            }
            else
                even++;
        }
        if(even == n || odd == n)   return true;
        for(int i=0; i<n; i++){
            if(!(nums1[i]&1)){
                if(nums1[i]<smallest_odd)
                    return false;
            }
        }
        return true;
    }
};