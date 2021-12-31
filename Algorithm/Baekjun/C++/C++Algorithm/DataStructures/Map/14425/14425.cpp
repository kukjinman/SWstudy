#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    map<string, bool> mp;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        //map의 [] operator를 사용하여 str을 추가 시킴.
        mp[str] = true;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;

        //
        if (mp[str])
            cnt++;
    }

    cout << cnt;

    return 0;
}
