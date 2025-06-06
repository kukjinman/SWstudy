#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Country {
    int gold;
    int silver;
    int bronze;
    int score() const {
        return gold * 1000 + silver * 100 + bronze;
    }
};

vector<Country> countries[1001]; // 최대 1000개 국가
int n, k;

int compare(const Country &a, const Country &b) {
    if (a.gold != b.gold) return a.gold > b.gold; // 금메달 수로 비교
    if (a.silver != b.silver) return a.silver > b.silver; // 은메달 수로 비교
    if (a.bronze != b.bronze) return a.bronze > b.bronze; // 동메달 수로 비교
    return false; // 동점인 경우 순서 유지
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++ ) {

        int country_id, gold, silver, bronze;
        cin >> country_id >> gold >> silver >> bronze;
        countries[country_id].push_back({gold, silver, bronze});
    }


    priority_queue<Country, vector<Country>, decltype(&compare)> pq(compare);


    for (int i = 1; i <= k; i++) {
        for (const auto &country : countries[i]) {
            pq.push(country);
        }
    }

    vector<Country> sortedCountries;
    while (!pq.empty()) {
        sortedCountries.push_back(pq.top());
        pq.pop();
    }
    sort(sortedCountries.begin(), sortedCountries.end(), compare);
    int rank = 1;
    int lastScore = -1;
    for (const auto &country : sortedCountries) {
        if (country.score() != lastScore) {
            lastScore = country.score();
            rank++;
        }
        cout << rank << " " << country.gold << " " << country.silver << " " << country.bronze << "\n";
    }
    

    return 0;

}


