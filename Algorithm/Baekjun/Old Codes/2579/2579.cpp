#include <iostream>
using namespace std;

int N;
#define Max 301

int s[Max];

void input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }
}

void solve()
{

    int cur = -1;
    int max = 0;

    int tripleCounter = 0;

    while(1)
    {

        if(cur == N-1){

            // triple check
            cur++;
            max += s[cur];
            tripleCounter++;
            cout << "s0] cur : " << cur << "max : " << max <<endl;


        }
        else if( cur >= N)
        {
            cout << "s4] cur : " << cur << "max : " << max <<endl;

            break;
        }

        cout << "cur : " << cur << endl;
        if(tripleCounter >= 3)
        {

            cur += 2;
            max += s[cur];
            tripleCounter = 0;

            
            cout << "s1] cur : " << cur << "max : " << max <<endl;

            continue;
        }

        if(s[cur+1] >= s[cur+2])
        {
            cur++;
            max += s[cur];
            tripleCounter++;

            cout << "s2] cur : " << cur << "max : " << max <<endl;

        }
        else{
            cur += 2;
            max += s[cur];

            tripleCounter = 0;
            cout << "s2] cur : " << cur << "max : " << max <<endl;

        }


    }




}




int main()
{
    input();

    solve();

    return 0;
}
