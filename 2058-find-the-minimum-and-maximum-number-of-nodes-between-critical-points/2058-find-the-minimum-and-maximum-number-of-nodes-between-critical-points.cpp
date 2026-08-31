/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head){
        vector<int> result = {-1, -1}; 
        int minDist = INT_MAX; 
        ListNode* prevNode = head;
        ListNode* currNode = head->next;
        int currInd = 1;
        int prevInd = 0;
        int firstInd = 0;

        while (currNode->next != nullptr){ 
            if ((currNode->val < prevNode->val &&currNode->val < currNode->next->val) ||
            (currNode->val > prevNode->val &&currNode->val > currNode->next->val)){ 
                if (prevInd == 0) {
                    prevInd = currInd;
                    firstInd = currInd;
                } 
                else{ 
                    minDist =
                        min(minDist, currInd - prevInd);
                    prevInd = currInd;
                }
            } 
            currInd++;
            prevNode = currNode;
            currNode = currNode->next;
        } 
        if (minDist != INT_MAX){
            int maxDist = prevInd - firstInd;
            result = {minDist, maxDist};
        } 
        return result;  
    }
};