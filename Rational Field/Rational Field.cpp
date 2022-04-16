
#include <iostream>
#include "Rational.h"

using std::cout;
using std::endl;

int main()
{
    Q q1 = Q(1, 2);
    Q q2 = Q(3, 4);

    cout << q1 << " + " << q2 << " = " << q1 + q2 << endl;
    cout << q1 << " - " << q2 << " = " << q1 - q2 << endl;
    cout << q1 << " * " << q2 << " = " << q1 * q2 << endl;
    cout << q1 << " / " << q2 << " = " << q1 / q2 << endl;
    cout << q1 << " % " << q2 << " = " << q1 % q2 << endl;

    cout << endl;

    cout << "+" << q1 << " = " << +q1 << endl;
    cout << "-" << q1 << " = " << -q1 << endl;
    cout << "~" << q1 << " = " << ~q1 << endl;

    cout << endl;

    cout << q1 << " to int = " << (int)q1 << endl;
    cout << q1 << " to float = " << (float)q1 << endl;

    cout << endl;

    cout << q1 << " == " << q2 << " : " << (q1 == q2) << endl;
    cout << q1 << " != " << q2 << " : " << (q1 != q2) << endl;
    cout << q1 << " < " << q2 << "  : " << (q1 < q2)  << endl;
    cout << q1 << " > " << q2 << "  : " << (q1 > q2)  << endl;
    cout << q1 << " <= " << q2 << " : " << (q1 <= q2) << endl;
    cout << q1 << " >= " << q2 << " : " << (q1 >= q2) << endl;

    cout << endl;

    cout << q1 << " == " << q1 << " : " << (q1 == q1) << endl;
    cout << q1 << " != " << q1 << " : " << (q1 != q1) << endl;
    cout << q1 << " < " << q1 << "  : " << (q1 < q1)  << endl;
    cout << q1 << " > " << q1 << "  : " << (q1 > q1)  << endl;
    cout << q1 << " <= " << q1 << " : " << (q1 <= q1) << endl;
    cout << q1 << " >= " << q1 << " : " << (q1 >= q1) << endl;

}