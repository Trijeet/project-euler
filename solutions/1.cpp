#include <iostream>

using namespace std;

int main()
{
    int limit = 1000;
    int sum = 0;

    for (int i=1; i<limit; i++) {
        if (i % 3 == 0 or i % 5 == 0) {
            sum += i;
        }
    }

    cout<<sum<<"\n";

    return 0;
}
