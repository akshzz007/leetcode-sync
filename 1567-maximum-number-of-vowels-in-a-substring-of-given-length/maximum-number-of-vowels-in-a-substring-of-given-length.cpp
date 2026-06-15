class Solution {
public:

    bool isvowel(char ch){

        return ch=='a' ||
               ch=='e' ||
               ch=='i' ||
               ch=='o' ||
               ch=='u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        // Initial window
        for(int i=0;i<k;i++){

            if(isvowel(s[i])){

                count++;
            }
        }

        int ans = count;

        int left = 0;
        int right = k;

        while(right < s.size()){

            // Left character remove
            if(isvowel(s[left])){

                count--;
            }

            left++;

            // Right character add
            if(isvowel(s[right])){

                count++;
            }

            ans = max(ans,count);

            right++;
        }

        return ans;
    }
};