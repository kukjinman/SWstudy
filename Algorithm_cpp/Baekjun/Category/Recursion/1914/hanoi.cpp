#include <iostream>
#include <cmath>

using namespace std;

int n;

void hanoi(int n, int start, int via, int target)
{

	if (n == 1)
	{
		cout << " last item moved to " << target << " from " << start << endl;
	}
	else
	{
		hanoi(n - 1, start, target, via);
		cout << start << " " << target << endl;
		hanoi(n - 1, via, start, target);

	}
}



int main()
{
	cin >> n;

	int total = pow(2, n);
	cout << total - 1 << endl;


	hanoi(n, 1, 2, 3);


	return 0;
}