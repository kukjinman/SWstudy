#include <iostream>
#include <algorithm>    // std::sort

using namespace std;

int N; 
int C;
int h[200001];
int ans = 0;
bool isPossible(int m_)
{
	int Counter = C;
	Counter--;
	int pre_index = 0;

	for (int i = 1; i < N; i++)
	{
		if (h[i] - h[pre_index] < m_)
		{
			continue;
		}
		else
		{
			Counter--;
			pre_index = i;
			//cout << " h : " <<  h[i] <<" i : " << i << " Counter : " << Counter << endl;
			
		}

	}

	if (Counter > 0 ) return false;
	else return true;

}

void solve()
{
	int s = 0, m = 0, e = 0;

	for (int i = 0; i < N; i++)
	{
		if (e < h[i])
		{
			e = h[i];
		}
	}


	while (s <= e)
	{
		//cout << " s : " << s << " e : " << e << endl;
		m = (s + e) / 2;
		//cout << " m : " << m << endl;
		if (isPossible(m))
		{
			ans = m;
			s = m + 1;
		}
		else
		{
			e = m - 1;
		}


	}

	cout << ans << endl;

}


int main()
{
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> h[i];
	}

	sort(h, h+ N);

	//for (int i = 0; i < N; i++)
	//{
	//	cout << h[i] << endl;
	//}

	solve();
	return 0;
}