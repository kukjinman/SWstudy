#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;
int main()
{

    int N;
    cin >> N;

    string str;

    queue<string> ans;

    for (int i = 0; i < N; i++)
    {

        cin >> str;

        // Stack LIFO
        // last input will be at the top. top will be poped first
        stack<char> st;

        bool failFlag = false;

        for (int j = 0; j < str.length(); j++)
        {

            if (str.at(j) == '(')
            {

                st.push(str.at(j));
            }
            else if (str.at(j) == ')')
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                {
                    failFlag = true;
                }
            }
        }

        if (!st.empty())
        {
            ans.push("NO");
            // cout << "YES" << endl;
        }
        else if (failFlag == true)
        {
            ans.push("NO");
        }
        else
        {
            ans.push("YES");
            // cout << "NO" << endl;
        }
    }

    for (int n = 0; n < N; n++)
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    return 0;
}
