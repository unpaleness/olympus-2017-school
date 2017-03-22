#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void turn_right(int &incX, int &incY)
{
  if (incX < 0)
  {
    incX = 0;
    incY = -1;
    return;
  }
  if (incX > 0)
  {
    incX = 0;
    incY = 1;
    return;
  }
  if (incY < 0)
  {
    incX = 1;
    incY = 0;
    return;
  }
  if (incY > 0)
  {
    incX = -1;
    incY = 0;
    return;
  }
}

int main()
{
  double pi { acos(-1) };
  int N;

  // Reading array size
  cin >> N;

  double *A = new double [N * N];

  int steps = N; // Steps before turning right
  int posX = -1;  // Current x position
  int posY = 0;  // Current y position
  int incX = 1;  // Increment of x on each step
  int incY = 0;  // Increment of y on each step
  int it = 0;    // Global iterator

  for (int j = 0; steps > 0; ++j)
  {
    for (int i = 0; i < steps; ++i)
    {
      posX += incX;
      posY += incY;
      A[posY * N + posX] = pi * it;
      ++it;
    }
    turn_right(incX, incY);
    if (!(j % 2)) --steps;
  }

  cout << setprecision(2);
  cout << fixed;
  for (int j = 0; j < N; ++j)
  {
    for (int i = 0; i < N; ++i)
      cout << setw(8) << A[j * N + i];
    cout << endl;
  }

  delete [] A;
  return 0;
}
