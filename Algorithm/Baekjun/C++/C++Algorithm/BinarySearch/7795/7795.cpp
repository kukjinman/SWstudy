#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v_A;
vector<int> v_B;

int binary_search(const int item)
{
    int s = 0;
    int e = v_B.size();
    int m = 0;

    // cout << "item : " << item << endl;
    while (s + 1 < e) {
        m = (s + e) / 2;
        // cout << "s : " << s << " m : " << m << " e : " << e << endl;
        if (v_B[m] < item)
            s = m;
        else
            e = m;
    }
    if (item > v_B[s]) {
        // cout << "item : " << item << "s : " << s << endl;
        s++;
    }

    return s;
}

int main(int argc, char** argv)
{
    int T, N, M;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int sol = 0;

        cin >> N >> M;

        v_A = vector<int>(N);
        v_B = vector<int>(M);

        for (int j = 0; j < N; j++) {
            cin >> v_A[j];
        }

        for (int k = 0; k < M; k++) {
            cin >> v_B[k];
        }

        sort(v_A.begin(), v_A.end());
        sort(v_B.begin(), v_B.end());

        for (int z = 0; z < N; z++) {

            int ret = binary_search(v_A[z]);

            if (ret > 0) {
                sol += ret;
            }

            // cout << "sol :  " << sol << endl;
        }

        cout << sol << endl;
        v_A.clear();
        v_B.clear();
    }

    return 0;
}
