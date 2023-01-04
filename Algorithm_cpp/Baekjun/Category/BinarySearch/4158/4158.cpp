#include <algorithm>
#include <iostream>
//#include <queue>
#include <algorithm>

using namespace std;

// 이 코드가 틀린 반례를 찾을 수가 없음....

int binary_search(const long long* arr_, int size, long long item)
{
    int s = 0;
    int e = size + 1;
    int m = 0;

    while (s <= e) {
        m = (s + e) / 2;

        if (arr_[m] == item) {
            return 1;
        } else if (arr_[m] > item) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return 0;
}

//int arr[500001];
//int arr_i[500001];

int main(int argc, char** argv)
{

    int N, M;

    while (1) {

        cin >> N >> M;

        if (N == 0 && M == 0) {
            // cout << " zero man " << endl;
            break;
        }

        long long* arr = new long long[N];
        long long* arr2 = new long long[M];

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> arr2[i];
        }

        int cnt = 0;

        if (N > M) {
            for (int i = 0; i < M; i++) {
                cnt += binary_search(arr, M, arr2[i]);
            }

        } else {

            for (int i = 0; i < N; i++) {
                cnt += binary_search(arr2, N, arr[i]);
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
