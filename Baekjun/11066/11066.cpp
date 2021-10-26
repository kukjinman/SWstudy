#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int T, K;

vector<int> v;


int main() {
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            int temp = 0;
            cin >> temp;
            v.push_back(temp);
        }

    sort(v.begin(), v.end());

    for (int i2 = 0; i2 < T; i2++)
    {
        int sum = 0;
        for (int j2 = 0; j2 < K; j2++)
        {
    
            if(j2 < 2)
            {
                sum += v.at(j2);
            }
            else
            {
                sum += v.at(j2);
                
            }
            
    
            cout << " d : "<<  sum << endl;


        }
        cout << sum << endl;
    }





    }



}