#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ant {
  double t;
  double k;
  double v;

  bool operator< (const Ant a) {
    return this->t < a.t;
  }

  friend ostream & operator<< (ostream & output, const Ant & ant) {
    output << ant.t << ' ' << ant.k << ' ' << ant.v;
    return output;
  }
};

int main() {
  double S; // Площадь отверстия
  int N;    // Количество муравьёв
  vector<Ant> ants;

  cin >> S >> N;

  if (S <= 0) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 0; i < N; ++i) {
    Ant ant;
    cin >> ant.t >> ant.k >> ant.v;
    ants.push_back(ant);
  }

  sort(ants.begin(), ants.end());

  // for (auto it = ants.begin(); it < ants.end(); ++it)
  //   cout << *it << endl;



}
