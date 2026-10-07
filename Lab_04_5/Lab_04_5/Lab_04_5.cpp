// Лабораторна робота № 4
// Варіант 14.


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    double R1, R2, x, y, r2;
    bool hit; // yes - якщо влучили, no - якщо промазали

    // R1 - зовнішній радіус, R2 - внутрішній: 0 < R2 < R1
    do {
        cout << "R1 = "; cin >> R1;
        cout << "R2 = "; cin >> R2;
    } while (!(R2 > 0 && R2 < R1));

    srand((unsigned)time(NULL));

    // 1 спосіб
    for (int i = 0; i < 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        r2 = x * x + y * y;
        hit = (r2 >= R2 * R2 && r2 <= R1 * R1) &&
            ((x >= 0 && y >= 0) || (x <= 0 && y <= 0));

        if (hit)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    cout << endl << fixed;

    // 2 спосіб
    for (int i = 0; i < 10; i++)
    {
        x = 2 * R1 * rand() / RAND_MAX - R1;
        y = 2 * R1 * rand() / RAND_MAX - R1;

        r2 = x * x + y * y;
        hit = (r2 >= R2 * R2 && r2 <= R1 * R1) &&
            ((x >= 0 && y >= 0) || (x <= 0 && y <= 0));

        cout << setw(8) << setprecision(4) << x << "    "
            << setw(8) << setprecision(4) << y << "    "
            << (hit ? "yes" : "no") << endl;
    }

    return 0;
}