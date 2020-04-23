#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;
#define MAX 200001
const double PI = acos(-1);
typedef complex<double> cpx;

void fft(vector<cpx> &a, bool inv=false)
{
	int n = a.size();
	for (int i=1, j=0; i<n; ++i) {
		int bit = (n >> 1);
		while (!((j ^= bit) & bit))
			bit >>= 1;
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int i=1; i<n; i<<=1) {
		double x = inv ? (PI / i) : (-PI / i);
		cpx w = {cos(x), sin(x)};
		for (int j=0; j<n; j+=(i << 1)) {
			cpx th = {1, 0};
			for (int k=0; k<i; ++k) {
				cpx tmp = a[i+j+k] * th;
				a[i+j+k] = a[j+k] - tmp;
				a[j+k] += tmp;
				th *= w;
			}
		}
	}

	if (inv)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void multiply(vector<cpx> &a)
{
	int n = 1;
	while (n <= a.size())
		n <<= 1;
	n <<= 1;
	a.resize(n);

	fft(a);
	for (int i=0; i<n; ++i)
		a[i] *= a[i];
	fft(a, 1);
}

int n, m, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<cpx> vec(MAX);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec[k] = cpx(1, 0);
	}
	vec[0] = cpx(1, 0);

	multiply(vec);

	cin >> m;
	int ans = 0;
	for (int i=0; i<m; ++i) {
		cin >> k;
		if (round(vec[k].real()) > 0)
			ans++;
	}
	cout << ans << '\n';

	return 0;
}
