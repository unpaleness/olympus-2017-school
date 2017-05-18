#include <iostream>
#include <queue>

using namespace std;

typedef short int sint;

struct Cage {
    sint x;
    sint y;
    sint z;
    Cage() {}
    Cage(const Cage &c) : x(c.x), y(c.y), z(c.z) {}
    Cage(sint x, sint y, sint z) : x(x), y(y), z(z) {}
};

int main() {
    sint N;
    sint *cave;
    char sym;
    queue <Cage> cages;

    cin >> N;

    int res { N * N * N };
    
    cave = new sint [N * N * N];
    for (int i = 0; i < N * N * N; ++i) {
        cin >> sym;
        if (sym == '#') {
            cave[i] = -2;
        } else {
            cave[i] = -1;
        }
        if (sym == 'M') {
            cave[i] = 0;
            cages.push( Cage(
                sint(i % N),
                sint((i / N) % N),
                sint(i / N / N)
            ) );
        }
    }

    // cout << cages.front().x << ' '
    //     << cages.front().y << ' '
    //     << cages.front().z << endl;
    // int it = 0;
    while (!cages.empty()) {
        // ++it;
        // cout << "\n===\n" << it << "\n===\n" << endl << cages.size() << endl;
        Cage cage(cages.front());
        cages.pop();
        if (cage.x > 0) {
            if (cave[cage.z * N * N + cage.y * N + cage.x - 1] == -1) {
                cave[cage.z * N * N + cage.y * N + cage.x - 1] =
                cave[cage.z * N * N + cage.y * N + cage.x] + 1;
                cages.push( Cage(cage.x - 1, cage.y, cage.z) );
            }
        }
        if (cage.x < N - 1) {
            if (cave[cage.z * N * N + cage.y * N + cage.x + 1] == -1) {
                cave[cage.z * N * N + cage.y * N + cage.x + 1] =
                cave[cage.z * N * N + cage.y * N + cage.x] + 1;
                cages.push( Cage(cage.x + 1, cage.y, cage.z) );
            }
        }
        if (cage.y > 0) {
            if (cave[cage.z * N * N + (cage.y - 1) * N + cage.x] == -1) {
                cave[cage.z * N * N + (cage.y - 1) * N + cage.x] =
                cave[cage.z * N * N + cage.y * N + cage.x] + 1;
                cages.push( Cage(cage.x, cage.y - 1, cage.z) );
            }
        }
        if (cage.y < N - 1) {
            if (cave[cage.z * N * N + (cage.y + 1) * N + cage.x] == -1) {
                cave[cage.z * N * N + (cage.y + 1) * N + cage.x] =
                cave[cage.z * N * N + cage.y * N + cage.x] + 1;
                cages.push( Cage(cage.x, cage.y + 1, cage.z) );
            }
        }
        if (cage.z > 0) {
            if (cave[(cage.z - 1) * N * N + cage.y * N + cage.x] == -1) {
                cave[(cage.z - 1) * N * N + cage.y * N + cage.x] =
                cave[cage.z * N * N + cage.y * N + cage.x] + 1;
                cages.push( Cage(cage.x, cage.y, cage.z - 1) );
            }
        }
        if (cage.z < N - 1) {
            if (cave[(cage.z + 1) * N * N + cage.y * N + cage.x] == -1) {
                cave[(cage.z + 1) * N * N + cage.y * N + cage.x] =
                cave[cage.z * N * N + cage.y * N + cage.x] + 1;
                cages.push( Cage(cage.x, cage.y, cage.z + 1) );
            }
        }
        // for (int j = 0; j < N; ++j) {
        //     for (int k = 0; k < N; ++k) {
        //         for (int i = 0; i < N; ++i)
        //             cout << '\t' << cave[k * N * N + j * N + i];
        //         cout << '\t';
        //     }
        //     cout << endl;
        // }
        // cout << "Next: " << cages.front().x << ' ' << cages.front().y << ' ' << cages.front().z << endl;
    }
    for (int i = 0; i < N * N; ++i) {
        if (cave[i] >= 0 && cave[i] < res) {
            res = cave[i];
        }
    }
    if (res >= N * N * N) {
        res = -1;
    }

    cout << res << endl;
}
