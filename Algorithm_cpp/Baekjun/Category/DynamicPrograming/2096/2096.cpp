#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int maxDP[4] = { 0, };
    int minDP[4] = { 0, };

    cin >> maxDP[0] >> maxDP[1] >> maxDP[2];
    minDP[0] = maxDP[0];
    minDP[1] = maxDP[1];
    minDP[2] = maxDP[2];


    for (int i = 1; i < n; i++)
    {
        int first, second, third;
        cin >> first >> second >> third;

        int max_temp0 = maxDP[0];
        int max_temp1 = maxDP[1];
        int max_temp2 = maxDP[2];

        maxDP[0] = max(max_temp0, max_temp1) + first;
        maxDP[1] = max(max(max_temp0, max_temp1), max_temp2) + second;
        maxDP[2] = max(max_temp1, max_temp2) + third;

        // cout << " 0 : " << maxDP[0] << " 1 : " << maxDP[1] << " 2 : " << maxDP[2] << endl;

        int min_temp0 = minDP[0];
        int min_temp1 = minDP[1];
        int min_temp2 = minDP[2];

        minDP[0] = min(min_temp0, min_temp1) + first;
        // cout << " t : " << min(min_temp0, min_temp1) << " first : " << first << endl;
        minDP[1] = min(min(min_temp0, min_temp1), min_temp2) + second;
        minDP[2] = min(min_temp1, min_temp2) + third;

        // cout << " 0 : " << minDP[0] << " 1 : " << minDP[1] << " 2 : " << minDP[2] << endl;

    }

    cout << max(max(maxDP[0], maxDP[1]), maxDP[2]) << " " << min(min(minDP[0], minDP[1]), minDP[2]);

    return 0;
}