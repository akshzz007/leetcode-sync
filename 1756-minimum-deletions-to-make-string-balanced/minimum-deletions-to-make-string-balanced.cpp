class Solution {
public:
    int minimumDeletions(string s) {
        
        int bCount = 0;   // kitne b aa chuke
        int del = 0;      // minimum deletions
        
        for(char ch : s) {
            if(ch == 'b') {
                bCount++;
            } 
            else { // ch == 'a'
                del = min(del + 1, bCount);
            }
        }
        
        return del;
    }
};
