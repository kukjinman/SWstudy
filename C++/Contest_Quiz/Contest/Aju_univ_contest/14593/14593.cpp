#include <iostream>
#include <queue>

using namespace std;

#define Max 10000

template <typename T>
void print_queue(T q)
{ // NB: pass by value so the print uses a copy

    cout << "----------------------------" << endl;

    while (!q.empty()) {
        std::cout << "[p] " << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';

    cout << "----------------------------" << endl;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N = 0;
    cin >> N;

    int S[Max] = {
        -1,
    };

    int C[Max] = {
        -1,
    };

    int L[Max] = {
        -1,

    };

    for (int i = 0; i < N; i++) {
        cin >> S[i] >> C[i] >> L[i];
    }

    int best = 0;

    int S_best = 0;
    int C_best = 0;
    int L_best = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] > S_best) {
            S_best = S[i];
            C_best = C[i];
            L_best = L[i];
            best = i;
        } else if (S[i] == S_best) {

            if (C[i] < C_best) {
                S_best = S[i];
                C_best = C[i];
                L_best = L[i];
                best = i;
            } else if (C[i] == C_best) {

                if (L[i] < L_best) {
                    S_best = S[i];
                    C_best = C[i];
                    L_best = L[i];
                    best = i;
                }
            }
        }
    }

    cout << best + 1 << endl;

    return 0;
}
