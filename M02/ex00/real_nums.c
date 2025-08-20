#include <stdio.h>
#include <ieee754.h>
#include <math.h>

#define LOG2_10 3.321928095
#define EPSILON 1e-12
#define flt_zero(x) (fabs(x) < EPSILON)

/**
 * maximum number of 0's right of decimal before using scientific notation
*/
int max_digit_rt = 3;

/**
 * maximum number of digits left of decimal
*/
int max_digit_lf = 5;

void print_real(double r, int width, int dec) {
    int     mag;
    double  fpart, temp;
    char    format[8];
    char    num_format[3] = {'l', 0, 0};
    union ieee754_double *dl;

    dl = (union ieee754_double *)&r;
    mag = (dl->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10;

    if(r == 0) {
        mag = 0;
    }

    if((mag > (max_digit_lf - 1)) || ( mag < (-max_digit_rt))) {
        num_format[1] = 'e';
        temp = r / pow(10, mag);
        fpart = temp - floor(temp);
    } else {
        num_format[1] = 'f';
        fpart = r -floor(r);
    }

    if(flt_zero(fpart)){
        dec = 0;
    }

    if(width == 0) {
        snprintf(format, 8, "%%.%d%s", dec, num_format);
    } else {
        snprintf(format, 8, "%%%d.%d%s", width, dec, num_format);
    }
    printf(format, r);
    printf("\n");
}


int main(void){
    double number = 3.1415926535;
    printf("normal      : %.10f\n", number);
    printf("scientific  : %e\n", number);
    printf("real number : ");
    print_real(number, 12, 6);
    return (0);
}
