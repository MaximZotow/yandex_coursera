#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;


int main()
{
	uint64_t N,W,H,D;
	uint64_t R;
	cin >> N >> R;
	uint64_t volumes = 0;
	for (int i=0;i<N;i++)
	{
		cin >> W >> H >> D;
		volumes+=(W*H*D*R);
	}
	cout << volumes;
	return 0;
}
