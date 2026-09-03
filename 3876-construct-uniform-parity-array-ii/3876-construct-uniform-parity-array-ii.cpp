class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        if(nums1[0]&1)  return true;
        else{
            for(int i=0; i<nums1.size(); i++){
                if(nums1[i]&1)
                    return false;
            }
        }
        return true;
    }
};