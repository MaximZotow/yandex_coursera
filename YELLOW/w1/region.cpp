#include <iostream>
#include<tuple>
#include<map>
#include<vector>
using namespace std;

int FindMaxRepetitionCount(const vector<Region>& regions)
{
    map <Region, int> repeats;
    int res = 0;
    for (auto& region : regions)
        res = max(res, ++repeats[region]);
    return res;
}

bool operator<(const Region& lhs, const Region& rhs)
{
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
            tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

