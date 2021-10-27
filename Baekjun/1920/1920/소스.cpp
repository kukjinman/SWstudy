#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 500000
int arr[MAX];


void binary_search(int* arr, int len, int key)
{
	int start = 0;
	int end = len - 1;
	int mid;

	while (end - start >= 0)
	{
		mid = (start + end) / 2;

		if (arr[mid] == key)
		{
			int index;
			int counter = 0;
			index = mid;
			while (arr[index] == key)
			{
				counter++;
				index++;

			}

			index = mid-1;
			while (arr[index] == key)
			{
				counter++;
				index--;

			}
			printf("%d\n",counter);

			return;

		}
		else if (arr[mid] > key)
		{
			end = mid -1;

		}
		else
		{
			start = mid + 1;

		}




	}
	printf("0\n");
}


int main()
{

	int n, m;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		//cin >> arr[i];
		scanf("%d", &arr[i]);

	}

	sort(arr, arr + n);

	cin >> m;

	for (int j = 0; j < m; j++)
	{
		int temp;
		//cin >> temp;
		scanf("%d", &temp);
		
		binary_search(arr, n, temp);

	}



}






