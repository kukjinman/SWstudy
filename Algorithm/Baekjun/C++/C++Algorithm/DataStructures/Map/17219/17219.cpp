#include <deque>
#include <iostream>
#include <map>

using namespace std;

int N, M;

map<string, string> m;
deque<string> dq;

void input()
{
    for (int i = 0; i < N; i++) {

        string url = "";
        string password = "";
        cin >> url >> password;
        m.insert({ url, password });
    }

    for (int j = 0; j < M; j++) {
        string target = "";
        cin >> target;

        dq.push_back(target);
    }
    /*
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        cout << " map f :  " << iter->first << " s : " << iter->second << endl;
    }

    while (!dq.empty()) {
        string tmp = dq.front();
        cout << "tmp : " << tmp << endl;
        dq.pop_front();
    }
    */
}

void solve()
{
    for (int j = 0; j < M; j++) {
        string tmp = dq.front();
        //cout << "tmp : " << tmp << endl;
        auto search = m.find(tmp);
        //cout << " map f :  " << search->first << " s : " << search->second << endl;
        cout << search->second << endl;
        dq.pop_front();
    }
}

int main(int argc, char** argv)
{

    cin >> N >> M;

    input();
    solve();

    return 0;
}