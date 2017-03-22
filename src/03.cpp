#include <iostream>
#include <string>

using namespace std;

int main()
{
    string little;
    string big;
    cin >> little >> big;
    size_t pos { big.find(little) };
    size_t nextPos { pos + little.size() };
    int res { 0 };
    // cout << big.size() << endl;
    // return 0;
    while (pos != string::npos && nextPos <= big.size())
    {
        // cout << pos << ' ' << res << endl;
        ++res;
        pos = big.find(little, nextPos);
        nextPos = pos + little.size();
    }
    cout << res << endl;
}
