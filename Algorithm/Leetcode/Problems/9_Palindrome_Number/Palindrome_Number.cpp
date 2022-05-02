class Solution {
public:
    bool isPalindrome(int x)
    {

        if (x < 0)
            return false;

        std::string s = to_string(x);

        if (s.length() % 2 == 1) {

            for (int i = 0; i <= s.length() / 2; i++) {

                // cout << " mid : " << s.length() / 2 << endl;

                // cout << " right : " << s.length() / 2 - i << " left : " << s.length() / 2 + i << endl;

                if (s[s.length() / 2 - i] == s[s.length() / 2 + i]) {
                    // cout << " yes" << endl;
                } else {
                    // cout << " no" << endl;
                    return false;
                }
            }

        } else {

            for (int i = 0; i < s.length() / 2; i++) {

                // cout << " mid : " << s.length() / 2 << endl;

                // cout << " right : " << s.length() / 2 - i << " left : " << s.length() / 2 + i + 1 << endl;

                if (s[s.length() / 2 - i - 1] == s[s.length() / 2 + i]) {
                    // cout << "1 yes" << endl;
                } else {
                    // cout << "1 no" << endl;
                    return false;
                }
            }
        }

        return true;
    }
};