#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;

map<long long, long long> m;

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{

    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {

        long long tmp = 0;
        cin >> tmp;

        m[tmp]++;
    }

    vector<pair<long long, long long>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        // cout << "f : " << v[i].first << " s : " << v[i].second << endl;
    }

    cout << v[0].first << '\n';

    return 0;
}