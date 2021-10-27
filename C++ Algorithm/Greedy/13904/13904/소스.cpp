#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector <pair<int, int>> v;

int main()
{
    cin >> N;


    for (int i = 0; i < N; i++)
    {
        int d, w;
        cin >> d >> w;

        v.push_back(make_pair(d, w));
    }

    sort(v.begin(), v.end());

    for (int j = 0; j < N; j++)
    {

        cout << "d : " << v.back().first << " w : " << v.back().second << endl;
        v.pop_back();


    }

    return 0;
}