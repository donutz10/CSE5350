#include <iostream>
#include <math.h>

using namespace std;

double g(double x)
{
    return (pow(x, 2) - 2);
}
double secnat(double p0, double p1, double tol, double n0)
{
    double p, q0, q1;
    double i = 2;
    q0 = g(p0);
    q1 = g(p1);
    while (i <= n0)
    {
        p = p1 - q1 * (p1 - p0) / (q1 - q0);
        if (fabs(p - p1) < tol)
        {
            cout << fabs(p - p1);
            cout
                << "\nThe procedure was successful at n0 iterations: " << i << "\nroot: " << p << endl;
            break;
        }
        i++;
        double q = g(p);
        if (q * q1 < 0)
        {
            p0 = p1;
            q0 = q1;
        }
        p1 = p;
        q1 = q;
        if (fabs(p - p1) > tol)
        {
            cout << "\nMethod failed after " << i << " iterations. last root: " << p;
            break;
        }
    }
}
int main()

{

    secnat(1.0, 2.0, 0.0001, 100);
    return 0;
}