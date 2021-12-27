#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>,greater<int>> q;

void input()
{
    cin >> N;

    for (int i = 0; i < N; i ++)
    {
        int buf;
        cin >> buf;
        q.push(buf);
    }
}


void solve()
{
    for (int i = 0; i < N; i++)
    {

        cout << q.top() << endl;
        q.pop();
    }
}

int main()
{
    input();
    solve();

    return 0;
}
