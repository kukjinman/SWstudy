#include <iostream>
#include<algorithm>


using namespace std;


int n, m;

int arr[500001];
int user[500001];


int binary_search(int cur)
{

	int ret = 0;
	int s = 0;
	int end = n;

	//cout << "cur :  " << cur << endl;


	while (s < end)
	{


		int mid = (s + end) / 2;

		//cout << " s : " << s << " mid : " << mid << " end : " << end << endl;

		if (arr[mid] == cur) {
			return 1;
		}
		else if (arr[mid] > cur)
		{
			end = mid;

		}
		else {
			s = mid+1;
		}

		


	}


	return ret;
}



void solve()
{

	for (int i = 0; i < m; i++)
	{
		int cur = user[i];


		cout << binary_search(cur) << " ";






	}




}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);


	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> user[i];
	}

	solve();




	return 0;
}
