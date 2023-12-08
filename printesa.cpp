#include <fstream>
#define VMAX 1000
using namespace std;
bool prim(int);
int main()
{
	bool p[VMAX+1];
	for (int i = 0; i <= VMAX; i++)
		p[i] = prim(i) ? 1 : 0;
	ifstream f("printesa.in");
	int K, H;
	f >> K >> H;
	while (H > 0)
	{
		int x;
		f >> x;
		p[x] = 0;
		H--;
	}
	f.close();
	int n = 0, v[K];
	for (int i = 2; n < K; i++)
		if (p[i]) v[n++] = i;
	ofstream g("printesa.out");
	for (int i = n-1; i >= 0; i--)
		g << v[i] << ' ';
	g.close();
	return 0;
}
bool prim(int n)
{
	if (n < 2) return 0;
	if (n == 2) return 1;
	if (n%2 == 0) return 0;
	for (int d = 3; d*d <= n; d += 2)
		if (n%d == 0) return 0;
	return 1;
}
