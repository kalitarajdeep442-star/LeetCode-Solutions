class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0;
        for(int yShft=0; yShft<img1.size(); yShft++){
            for(int xShft=0; xShft<img1.size(); xShft++){
                ans = max(ans, shiftAndCount(xShft,yShft,img1,img2));
                ans = max(ans, shiftAndCount(xShft,yShft,img2,img1));
            }
        }
        return ans;
    }
    int shiftAndCount(int xShft, int yShft, vector<vector<int>>&img1, vector<vector<int>>&img2){
        int leftShiftCnt=0, rightShiftCnt=0;
        int img2Row=0;
        for(int img1Row=yShft; img1Row<img1.size(); img1Row++){
            int img2Col=0;
            for(int img1Col=xShft; img1Col<img1.size(); img1Col++){
                if(img1[img1Row][img1Col] == 1 && img1[img1Row][img1Col] == img2[img2Row][img2Col])
                    leftShiftCnt++;
                if(img1[img1Row][img2Col] == 1 && img1[img1Row][img2Col] == img2[img2Row][img1Col])
                    rightShiftCnt++;
                img2Col++;
            }
            img2Row++;
        }
        return max(leftShiftCnt, rightShiftCnt);
    }
};