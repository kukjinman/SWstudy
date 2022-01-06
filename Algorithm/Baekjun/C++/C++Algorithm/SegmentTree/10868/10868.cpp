#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0;

vector<int> Arr;
vector<int> Segment_Tree;
vector<pair<int, int>> Cmd;

void input()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        Arr.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Cmd.push_back(make_pair(a, b));
    }
}

int main(int argc, char* argv[])
{
    input();

    return 0;
}