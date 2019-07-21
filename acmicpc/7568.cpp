#include <iostream>
using namespace std;
#define MAX 51

int a[MAX], b[MAX], c[MAX];

int main()
{
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i] >> b[i];

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (i != j)
				if (a[i] < a[j] && b[i] < b[j])
					c[i]++;

	for (int i=0; i<n; ++i)
		cout << c[i]+1 << " ";

	return 0;
}
