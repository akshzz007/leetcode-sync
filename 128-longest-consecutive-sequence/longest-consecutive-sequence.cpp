class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Agar array empty hai
        if(nums.empty())
            return 0;

        // HashSet banaya
        unordered_set<int> st;

        // Saare elements set me daal diye
        for(int num : nums){
            st.insert(num);
        }

        int longest = 0;

        // Har element traverse karo
        for(int num : st){

            // Agar previous number exist nahi karta
            // to ye sequence ka start hai
            if(st.find(num - 1) == st.end()){

                int currentNum = num;
                int currentLength = 1;

                // Consecutive numbers check karo
                while(st.find(currentNum + 1) != st.end()){

                    currentNum++;

                    currentLength++;
                }

                // Maximum update karo
                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};