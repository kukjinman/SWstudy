#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<pair<long, long>> v;
priority_queue<long long> pq;


// ������ �ּҰ��� ã�µ�, ������ �������� �ʰ� ���� ���ŵȴ�.
// �׷��Ƿ� ���� ���� ������������ �����Ͽ� ���� ���� ������ �ö󰡴� loop�� �¿��
// loop�ȿ��� ��ȣ�� ���� -�� �־��־� ���� ���� ���밪�� top���� ���� ���ش�. (cmp�� ����ص� ��)
// pq�� ����Ͽ� ���� ��ȣ���� n���� ������ ���ش�. ���� v[i]�� ���� ��ȣ���� pq.top�� ����Ͽ� ���� 
// sum>=m Ȯ���� �ϰ� ��.
// �����ϸ� return���� ����


int main(int argc, char** argv)
{

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        long long like = 0;
        long long alc = 0;
        cin >> like >> alc;

        v.push_back(make_pair(alc, like));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        //cout << " vi f: " << v[i].first << " s : " << v[i].second << endl;

    }
    //cout << " ---------------------------" << endl;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        //cout << " vi f: " << v[i].first << " s : " << v[i].second << endl;
        pq.push(-v[i].second);
        sum += v[i].second;

        if (pq.size() > n)
        {
            
            sum += pq.top();
            pq.pop();
        }

        if (pq.size() == n && sum >= m)
        {
            cout << v[i].first << endl;
            return 0;
        }

    }

    cout << "-1" << endl;

    return 0;
}
