#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
  long long int N;
  long long int M;
  int K { 0 };
  long long int prev1 { 0 };
  long long int prev2 { 1 };

  cin >> N >> M;

  while (prev1 + prev2 <= M) {
    if (prev1 + prev2 >= N) {
      ++K;
      // cout << '+';
    }
    else {
      // cout << '-';
    }
    // cout << prev1 + prev2 << ' ' << K << endl;
    prev2 += prev1;
    prev1 = prev2 - prev1;
  }
  cout << K << endl;
}
