#include <iostream>

#define MAX 100000
#define LITER_MAX 1000000000

using namespace std;

int station[MAX];
int line[MAX];

int main()
{

    int N = 0;

    int cost = 0;
    cin >> N;

    for (int i = 0; i <= N - 2; i++)
    {
        cin >> line[i];
    }

    for (int j = 0; j <= N - 1; j++)
    {
        cin >> station[j];
    }

    int min = LITER_MAX;
    int cumul_line = 0;

    int reset = 0;

    for (int z = N-2; z >= 0; z--)
    {
        

        if( station[z] <= min)
        {

            if(reset >=1 )
            {

            min = station[z];
            cumul_line += line[z];
            cost += (min * cumul_line);
        //             cout << "[c] : " << cost << endl;
        // cout << "[c](min * cumul_line): " << (min * cumul_line) << endl;

            min = LITER_MAX;
            cumul_line = 0;
            reset = 0;

            continue;
            }
            else
            {
                            min = station[z];
            cumul_line += line[z];
            reset++;
            }
            


            
            // cout << "stage 1 z: " << z << " reset : " <<reset << endl;
            // cout << "min : " << min << endl;
            // cout << "station : " << station[z] << endl;

        }
        else
        {
            cumul_line += line[z];

            // cout << "stage 1 z: " << z  << endl;
        }
        
        if(z == 0)
        {
            

           cost += (station[0] * cumul_line);
        // cout << "[c] : " << cost << endl;


        }

//반례
// 5
// 3 2 1 4
// 5 8 9 4 1

            cout << "stage 1 z: " << z << " reset : " <<reset << endl;
            cout << "min : " << min << endl;
            cout << "station : " << station[z] << endl;
        cout << "[c] : " << cost << endl;

    }

        

        cout << cost << endl;

    return 0;
}
