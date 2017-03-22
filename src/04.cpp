#include <iostream>

using namespace std;

int figs(int sym, int x)
{
    int res { 0 };
    while (x != 0)
    {
        if (x % 10 == sym)
            ++res;
        x /= 10;
    }
    return res;
}

int main()
{
    int N;
    int sym;
    long long int res { 0 };
    // long long int res2 { 0 };
    cin >> N >> sym;
    for (int i = 1; i <= N; ++i)
    {
        res += figs(sym, i);
        // res2 += fig(sym, i);
    }
    cout << res << endl;
    // cout << res2 << endl;
}
