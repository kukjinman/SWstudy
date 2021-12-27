#include <iostream>
#include <stack>

using namespace std;
int K ;

stack<int> s;

int main()
{
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int input = -1;
        cin >> input;

        if( input == 0)
        {
            if(!s.empty())
            s.pop();
        }
        else{

            s.push(input);
        }
    }

    int sum = 0;

    while(!s.empty())
    {
        sum += s.top();
        s.pop();
    }

    cout << sum << endl;

    return 0;
}