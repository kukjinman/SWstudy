#include <iostream>
#include <stack>

using namespace std;

int n;
int arr[1000001];

stack<int> s;

int sol[1000001];

void solve()
{

    for (int i = n - 1; i > 0; i--)
    {

            if(arr[i] > s.top())


        while(!s.empty())
        {
            if(arr[i] > s.top())
                s.pop();
        }

        if(s.empty())
        {

        }

        cout << s.top() << " ";
        s.push(arr[i]);


    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve();

    return 0;
}