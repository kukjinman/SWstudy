#include <iostream>
#include <map>
using namespace std;

int n, k, m;
long long total = 0;
map<int, long long> mp;


void recurse(int cnt)
{
    // cout << " master : " << cnt <<"----------------" << endl;
    if (cnt < n)
    {
        mp[cnt]++;
        total++;
        // cout << " mp up " << mp[cnt] << " cnt : " << cnt << endl;
        return;
    }

    int cur = cnt - n;

    for (int i = 0; i <= k; i++)
    {
        // cout << " rec : "<< cur + i << endl;
        recurse(cur + i);
    }

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> m;

    recurse(m);

    int mod = 1000000007;

    map<int, long long> ans;

    for (int i = 0; i < n; i++)
    {
        ans[i] = (mp[i] * mod / total);
        // cout << "ans["<< i <<"]" <<  ans[i] << endl;
        cout << ans[i] << endl;
    }

    return 0;
}