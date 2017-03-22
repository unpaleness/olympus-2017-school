#include <iostream>

using namespace std;

// M - current sum to disolve
// iCoin - index of coin
int amount_of_variants(int M, int iCoin, int *A)
{
    int res { 0 };
    if (iCoin <= 0)
        return 1;
    int rem { M };
    do
    {
        res += amount_of_variants(rem, iCoin - 1, A);
        rem -= A[iCoin];
    } while (rem >= 0);
    return res;
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    int M;
    cin >> M;
    cout << amount_of_variants(M, N - 1, A) << endl;
}
