class Solution {
public:
    char processStr(string s, long long k) {

        long long len = 0;

        // Pass 1: final length
        for(char c : s){

            if(c >= 'a' && c <= 'z'){
                len++;
            }

            else if(c == '*'){

                if(len > 0)
                    len--;
            }

            else if(c == '#'){
                len *= 2;
            }

            else if(c == '%'){
                // length same
            }
        }

        if(k >= len)
            return '.';

        // Pass 2: reverse traversal

        for(int i = s.size()-1; i >= 0; i--){

            char c = s[i];

            if(c >= 'a' && c <= 'z'){

                if(k == len-1)
                    return c;

                len--;
            }

            else if(c == '*'){

                len++;
            }

            else if(c == '#'){

                long long half = len/2;

                k %= half;

                len = half;
            }

            else if(c == '%'){

                k = len-1-k;
            }
        }

        return '.';
    }
};