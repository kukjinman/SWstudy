#include <algorithm>
#include <iostream>
//#include <queue>
#include <algorithm>


using namespace std;


int binary_search(const int* arr_, const int size, const int item)
{
    int s = 0;
    int e = size - 1;
    int m;

    while (s <= e)
    {
        m = (s + e) / 2;

        if (arr_[m] == item)
            return 1;
        else if (arr_[m] > item)
            e = m - 1;
        else
            s = m + 1;
    }

    return 0;

}
//int arr[500001];
//int arr_i[500001];

int main(int argc, char** argv)
{

    int N, M;
    cin >> N;

    int *arr = new int[N];

    //cout << "size of arr : " << _msize(arr) / sizeof(int) << endl;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cin >> M;

    //queue <int> q;
    int* arr_i = new int[M];


    for (int j = 0; j < M; j++)
    {
        cin >> arr_i[j];
    }

    //cout << " q size : " << q.size() << endl;


    for (int k = 0; k < M; k++)
    {

        int ret = binary_search(arr, N, arr_i[k]);
        
        // This makes the timeout............... endl makes the timeout..!!!
        //cout << ret << endl;

        cout << ret << ' ';
    }
    cout << endl;

    return 0;
}

