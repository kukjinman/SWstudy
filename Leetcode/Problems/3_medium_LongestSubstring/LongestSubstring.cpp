// #include <iostream>
// #include <string>

// using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {

        int ret = 0;

        string ans = "";

        string max = "";

        for (int i = 0; i < s.size(); i++) {
            char cur = s.at(i);

            if (ans.find_first_of(cur) == string::npos) {
                ans += cur;
                if (max.size() < ans.size()) {
                    max = ans;
                    // cout << " max : " << max.size() << endl;
                }

            } else {

                // cout << " max : " << max.size() << " ans : " << ans.size() << endl;
                if (max.size() < ans.size()) {
                    max = ans;
                    // cout << " max : " << max.size() << endl;
                }

                ans = ans.substr(ans.find_first_of(cur) + 1);
                ans += cur;
            }
            // cout << " i : " << i << " ans : " << ans << endl;
        }
        // cout << " max : " << max << endl;
        ret = max.size();

        return ret;
    }
};

// int main()
// {
//     Solution test;

//     int ret = test.lengthOfLongestSubstring("dvdf");

//     cout << " ret : " << ret << endl;
// }