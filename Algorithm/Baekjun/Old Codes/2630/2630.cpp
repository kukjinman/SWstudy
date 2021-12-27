#include <iostream>

using namespace std;

int N;

#define MAX 128
int map[MAX][MAX];

void input()
{
    cin >> N;

    for (int i = 0; i < N; i ++)
    {
        for (int j = 0; j < N; j++)
        {

            cin >> map[i][j];

        }
    }




}


int main()
{
    input();



    return 0;
}
