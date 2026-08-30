class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minidx = min_element(nums.begin(), nums.end())-nums.begin();
        int maxidx = max_element(nums.begin(), nums.end())-nums.begin();
        int left = min(minidx, maxidx);
        int right = max(minidx, maxidx);
        int front = right+1;
        int back = n-left;
        int front_back = (left+1)+(n-right);
        return min({front, back, front_back});
    }
};