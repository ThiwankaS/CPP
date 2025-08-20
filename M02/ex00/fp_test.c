#include <stdio.h>
#include <math.h>

double magnitude(double re, double im) {
    /**
     * can not handle over flow the result will be inf
    */
    //return (sqrt(re * re + im * im));

    /**
     * computes the Euclidean length safely, avoiding overflow/underflow
     * that can happen with sqrt(x*x + y*y).
    */
    //return (hypot(re, im));

    double r;

    re = fabs(re);
    im = fabs(im);
    if (re > im) {
        r = im / re;
        return (re * sqrt(1.0 + r * r));
    }
    if (im == 0.0) {
        return (0.0);
    }
    r = re / im;
    return (im * sqrt(1.0 + r * r));
}


int main (void) {
    double re = 1e200;
    double im = 1e200;
    double result = magnitude(re, im);
    printf("Result : %f\n", result);
    return (0);
}
