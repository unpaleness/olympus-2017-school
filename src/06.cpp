#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <iomanip>

using namespace std;

struct Ant {
  double id;  // Индекс
  double t;   // Время до возвращения
  double k;   // Оставшееся количество материала
  double v;   // Скорость работы
  double tkv; // Время, которое затратит муравей, чтобы израсходовать
              // оставшиеся у него ресурсы

  bool operator< (const Ant a) {
    if (this->t == a.t)
      return this->tkv < a.tkv;
    return this->t < a.t;
  }

  friend ostream & operator<< (ostream & output, const Ant & ant) {
    output << ant.t << ' ' << ant.k << ' ' << ant.v;
    return output;
  }
};

int main() {
  cout << setprecision(4);
  cout.setf(ios::fixed);

  double S;             // Площадь отверстия
  int N;                // Количество муравьёв
  double T { 0.0 };     // Затраченное время
  vector<Ant> ants;

  cin >> S >> N;

  // if (S <= 0) {
  //   cout << 0 << endl;
  //   return 0;
  // }

  for (int i = 0; i < N; ++i) {
    Ant ant;
    ant.id = i;
    cin >> ant.t >> ant.k >> ant.v;
    ant.tkv = ant.k / ant.v;
    ants.push_back(ant);
  }

  while (S > 0.0)
  {
    double v { 0.0 };
    double dS { 0.0 };
    double tArrive { DBL_MAX };
    double tRepair { DBL_MAX };

    for (auto it : ants) {
      if (it.t <= 0) {
        if (it.tkv > 0.0) {
          v += it.v;
          if (tRepair > it.tkv) {
            tRepair = it.tkv;
          }
        }
      }
      else {
        if (tArrive > it.t) {
          tArrive = it.t;
        }
      }
    }

    if (v <= 0.0 && tArrive == DBL_MAX) {
      break;
    }

    if (tRepair > tArrive) {
      tRepair = tArrive;
    }

    dS = v * tRepair;

    if (dS > S)
    {
      dS = S;
      tRepair = dS / v;
    }

    for (auto &it : ants) {
      if (it.t <= 0) {
        if (it.tkv > 0) {
          it.k -= it.v * tRepair;
          it.tkv -= tRepair;
        }
      }
      else {
        it.t -= tRepair;
      }
    }

    T += tRepair;
    S -= dS;

    // cout << endl << "time: " << T << endl;
    // cout << "v: " << v << endl;
    // cout << "S: " << S << endl;
    // cout << "ants:" << endl;
    // for (auto it : ants) {
    //   cout << '\t' << it.id << '\t' << it.t << '\t' << it.k << '\t'
    //        << it.v << '\t' << it.tkv << endl;
    // }
  }

  if (S <= 0.0) {
    cout << T << endl;
  }
  else {
    cout << -1 << endl;
  }
}
