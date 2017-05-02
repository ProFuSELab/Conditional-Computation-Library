#include <iostream>
#include <cmath>

using namespace std;

double a[1048576];

int main()
{
	int fod;
	cin >> fod;
	for (int i = 0; i < pow(2, 10); i++)
		a[i] = i;
	/*
	a[0] = 0;
	a[1] = 0.1;
	a[2] = 0.1;
	a[3] = 0.4;
	a[4] = 0.1;
	a[5] = 0.3;
	a[6] = 0.3;
	a[7] = 1;
	*/
	// m() 0	0.1	0.1	0.2	0.1	0.1	0.1	0.3
	// Bl() 0	0.1	0.1	0.4	0.1	0.3	0.3	1
	for (int i = 0; i < pow(2, fod); i++)
		cout << a[i] << " ";
	cout << endl;
	for (int i = fod - 1; i >= 0; i--)
	{
	   for (int j = 0; j * pow(2, i) < pow(2, fod); j += 2)	
		   for (int k = 0; k < pow(2, i); k++)
			   a[j * (int)pow(2, i) + k + (int)pow(2, i)] -= a[j * (int)pow(2, i) + k];
		for (int m = 0; m < pow(2, fod); m++)
			cout << a[m] << " ";
		cout << endl;
	}
	return 0;
}
