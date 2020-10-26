#include <iostream>

using namespace std;

int main()
{
    int limit = 4000000;
    int a = 1;
    int b = 2;
    int c = a + b;
    int sum = 0;

    while (c <= limit) {
        if (c % 2 == 0) {
            sum += c;
        }
        a = b;
        b = c;
        c = a + b;
    }

    sum += 2;
    cout<<sum<<"\n";

    return 0;
}
