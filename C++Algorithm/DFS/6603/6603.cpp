#include <iostream>

using namespace std;

int arr[49];
int result[6];
int k = -1;

void dfs(int s, int depth)
{
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = s; i < k; i++) {
        result[depth] = arr[i];
        dfs(i + 1, depth + 1);
    }
}

int main(int argc, char** argv)
{

    while (1) {
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        dfs(0, 0);
        cout << endl;
    }

    return 0;
}
