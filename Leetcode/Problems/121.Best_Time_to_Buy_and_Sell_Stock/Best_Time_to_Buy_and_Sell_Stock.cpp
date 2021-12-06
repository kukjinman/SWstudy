
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {

        int ret = 0;
        int max = 0;
        int min = INT_MAX;

        int profit = 0;
        int next_profit = 0;
        vector<int> v = prices;

        for (auto it = v.begin(); it != v.end(); it++) {
            int cur = 0;
            cur = *it;
            cout << "cur : " << cur << endl;

            if (cur < min) {
                min = cur;
                max = 0;
            } else {
                if (cur > max) {
                    max = cur;

                    if (max - min > profit) {
                        profit = max - min;
                    }

                } else {
                }
            }
        }

        ret = profit;

        return ret;
    }
};