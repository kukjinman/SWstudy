#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int check(const string& s, int l, int r, bool chance) {
    while (l < r) {
        if (s[l] == s[r]) {
            l++; r--;
        } else if (chance) {
            // 둘 중 하나라도 회문이면 유사회문
            if (check(s, l+1, r, false) == 0 || check(s, l, r-1, false) == 0)
                return 1;
            else
                return 2;
        } else {
            return 2;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        cout << check(s, 0, s.size()-1, true) << "\n";
    }
    return 0;
}