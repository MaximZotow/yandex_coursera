#include <iostream>
#include<vector>
#include<cstdint>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int64_t> temps;
    vector<int64_t> res(1);
    res[0] = 0;
    int64_t sr = 0;
    for (int i = 0; i < n; i++)
    {
        int64_t temp;
        cin >> temp;
        temps.push_back(temp);
        sr += temp;
    }
    sr /= int(temps.size());
    //cout << sr << endl;
    for (int i = 0; i < n; i++)
    {
        if (temps[i] > sr)
        {
            res[0] += 1;
            res.push_back(i);
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (i == 0)
            cout << res[i] << endl;
        else if (i < res.size() - 1)
            cout << res[i] << " ";
        else cout << res[i] << endl;
    }
}
