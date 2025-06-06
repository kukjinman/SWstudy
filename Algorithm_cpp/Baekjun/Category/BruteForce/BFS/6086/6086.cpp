#include <iostream>
#include <vector>

using namespace std;

int n;

vector<vector<int>> pipe;


// 5
// A B 3
// B C 3
// C D 5
// D Z 4
// B Z 6

int toIdx(char c) {
    if (c > 90) { // 소문자
        return c - 'a' + 1; // 'a'는 1번 인덱스
    } else { // 대문자
        return c - 'A' + 27; // 'A'는 27번 인덱스
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    pipe.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
    
        char a, b;
        int cost;
        cin >> a >> b >> cost;

        a = toIdx(a); // A를 인덱스로 변환
        b = toIdx(b); // B를 인덱스로 변환
        

        pipe[a][b] = cost; // A -> B
        pipe[b][a] = cost; // B -> A (무방향 그래프이므로 양방향으로 저장)
        cout << "Pipe from " << a << " to " << b << " with cost " << cost << "\n";
    }

    cout << pipe[1].size() << "\n"; // A에서 연결된 파이프의 개수 출력


}