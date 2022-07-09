//二人の子供
include <iostream>


//回転行列
int KaitenGyouretu(double a, double b, double d){
    double rad = M_PI * d / 180;
    cout << setprecision(24) << (long double)cos(rad) * a + (long double)-sin(rad) * b << ' '
    << (long double)sin(rad) * a + (long double)cos(rad) * b << endl;
}
