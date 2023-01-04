#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int e : scoville) pq.push(e);

    while (pq.top() < K) {
        // ���ں� ������ K �̻����� ���� �� ���� ��� -1 ����
        if (pq.size() == 1) return -1;

        // ���� ���� ��
        int tmp1 = pq.top();
        pq.pop();

        // �״��� ���� ��
        int tmp2 = pq.top();
        pq.pop();

        // ���� �� �ֱ�
        int new_scoville = tmp1 + (tmp2 * 2);
        pq.push(new_scoville);

        answer++;
    }

    return answer;
}
