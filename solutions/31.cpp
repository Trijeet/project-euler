#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll dp[201][201];
int currency_array[] = {1, 2, 5, 10, 20, 50, 100, 200};
vector<int> currency(begin(currency_array), end(currency_array));
int goal = 200;

void init()
{
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) {
            dp[i][j] = -1;
        }
    }
}

ll count_ways(int got, int last_used)
{
    int remaining = goal - got;
    if (remaining == 0) {
        return 1;
    }
    if (remaining < 0) {
        return 0;
    }
    if (dp[got][last_used] != -1) {
        return dp[got][last_used];
    }

    ll ways = 0;
    for (int i : currency) {
        if (last_used <= i) {
            ways += count_ways(got + i, i);
        }
    }
    dp[got][last_used] = ways;
    // cout << got << " " << ways <<"\n";
    return ways;
}

int main()
{
    init();
    ll no_of_ways = count_ways(0, 0);
    cout << no_of_ways << "\n";

    return 0;
}
