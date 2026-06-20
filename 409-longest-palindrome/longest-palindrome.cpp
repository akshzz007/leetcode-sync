class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char,int> freq;

        for(char ch:s){
            freq[ch]++;
        }

        int ans=0;

        bool oddfound=false;

        for(auto it:freq){

            int count=it.second;

            if(count%2==0){

                ans+=count;
            }

            else{

                ans+=count-1;

                oddfound=true;
            }
        }

        if(oddfound){

            ans+=1;
        }

        return ans;
    }
};