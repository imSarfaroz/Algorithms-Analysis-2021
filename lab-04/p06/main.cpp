#include <iostream>
#include <cstdint>

using namespace std;

int64_t fib(int64_t n)
{
    if(n <= 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int64_t fibIter(int64_t n)
{
    if (n <= 1)
    {
        return 1;
    }
    
    int64_t a = 1;
    int64_t b = 1;

    for (int i = 2; i <= n; i++)
    {
        int64_t t = a + b;
        a = b;
        b = t;
    }
    return b;
}

int main()
{
    for (int n; cin >> n;)
    {
        cout << "Fib(" << n << ") = " << fibIter(n) << endl;
    }
}