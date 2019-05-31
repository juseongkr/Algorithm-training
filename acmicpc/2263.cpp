#include <iostream>
using namespace std;
#define MAX 1000001

int n, in[MAX], po[MAX], idx[MAX];

void pre(int in_left, int in_right, int po_left, int po_right)
{
	if (in_left > in_right || po_left > po_right)
		return;

	int root = po[po_right];
	int pos = idx[root];
	cout << root << " ";

	pre(in_left, pos-1, \
	    po_left, po_left + pos - in_left - 1); 

	pre(pos+1, in_right, \
	    po_left + pos - in_left, po_right-1);
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> in[i];
	for (int i=0; i<n; ++i)
		cin >> po[i];

	for (int i=0; i<n; ++i)
		idx[in[i]] = i;

	pre(0, n-1, 0, n-1);

	return 0;
}
