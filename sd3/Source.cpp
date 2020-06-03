#include <iostream>
using namespace std;

int main()
{
	int min, buf;
	int N;
	cout << "Input amout of nails" << endl;
	cin >> N;

	int* a = new int[N];
	int* dx = new int[N];

	cout << "Input coordinates of nails" << endl;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < N; ++i)
	{
		min = i;
		for (int j = i + 1; j < N; ++j)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		buf = a[i];
		a[i] = a[min];
		a[min] = buf;
	}

	dx[1] = a[1] - a[0];
	dx[2] = a[2] - a[0];
	for (int i = 3; i < N; ++i)
	{
		if (dx[i - 1] < dx[i - 2])
		{
			dx[i] = dx[i - 1] + a[i] - a[i - 1];
		}
		else
		{
			dx[i] = dx[i - 2] + a[i] - a[i - 1];
		}
	}

	cout << "Min length of ropes is " << dx[N - 1] << endl;
	return 0;
}
