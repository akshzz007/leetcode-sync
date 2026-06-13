class Solution {
public:
    string reverseWords(string s) {
                int n = s.length();
        string ans = "";
        string word = "";

        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        int i = 0;
        while (i < n) {
            // Step 2: Skip leading spaces
            while (i < n && s[i] == ' ') i++;

            // Step 3: Store a word
            word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Step 4: Reverse each word to make it correct
            reverse(word.begin(), word.end());

            // Step 5: Add it to answer (with space if not first)
            if (word.length() > 0) {
                if (ans.length() > 0) ans += " ";
                ans += word;
            }
        }

        return ans;

    }
};