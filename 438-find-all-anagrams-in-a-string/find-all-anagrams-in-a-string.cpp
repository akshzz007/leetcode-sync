class Solution {
public:

    vector<int> findAnagrams(string s, string p) {

        // Agar p bada hai to impossible
        if (s.size() < p.size())
            return {};

        vector<int> si(26,0);
        vector<int> pi(26,0);

        int left = 0;
        int right = 0;

        // Initial window banao
        while(right < p.size()){

            si[s[right]-'a']++;

            pi[p[right]-'a']++;

            right++;
        }

        right--;

        vector<int> ans;

        while(right < s.size()){

            // Frequency same => anagram
            if(si == pi)
                ans.push_back(left);

            // Left remove karo
            si[s[left]-'a']--;

            left++;

            // Window aage badhao
            right++;

            // Naya character add karo
            if(right != s.size()){

                si[s[right]-'a']++;

            }
        }

        return ans;
    }
};