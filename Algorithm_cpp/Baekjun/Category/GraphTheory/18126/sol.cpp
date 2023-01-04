#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solve()
{
}

int n = 0;
queue<pair<pair<int, int>, int>> q;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a = 0;
        int b = 0;
        int dist = 0;

        cin >> a >> b >> dist;

        q.push(make_pair(make_pair(a, b), dist));
    }

    while (!q.empty()) {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int dist = q.front().second;

        cout << "a : " << a << " b : " << b << " dist : " << dist << endl;
    }

    return 0;
}