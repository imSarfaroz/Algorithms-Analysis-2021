#include <iostream>
#include <cstdint>

using namespace std;

int gcdAux(int64_t a, int64_t b)
{
    if (a == 0 || b == 0)
    {
        return max(a, b);
    }
    
    // while (b != 0)
    // {
    //     int64_t r = a % b;
    //     a = b;
    //     b = r;
    // }
    // return a;

    return gcdAux(b, a % b);
}

int gcd(int64_t a, int64_t b)
{
    if (a == 0 && b == 0)
    {
        throw invalid_argument("gcd(0, 0) is not defined");
    }
    return gcdAux(abs(a), abs(b));
}

int main()
{
    for (int64_t a, b; cin >> a >> b;)
    {
        try
        {
            int64_t r = gcd(a, b);
            cout << "gcd(" << a << ", " << b << ") = " << r << endl;
        }
        catch (invalid_argument &e)
        {
            cerr << e.what() << endl;
        }
    }
}