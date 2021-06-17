#include <iostream>
#include<cstdint>
using namespace std;

int main()
{
    uint64_t N;
    uint64_t R;
    cin >> N >> R;
    //cout << N << " " << R << endl;
    uint64_t res = 0;
    for (uint64_t i = 0; i < N; i++)
    {
        uint64_t W,H,D;
        cin >> W >> H >> D;
        res += W*H*D*R;
        //cout << i << "-й "<< W << " " << H << " " << D << " " << R << " " << W*H*D*R << endl;
    }
    cout << res << endl;
}
