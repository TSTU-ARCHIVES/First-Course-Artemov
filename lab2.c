
#include <stdio.h>
int main() {
    float n;
    printf("input temperature in celsius: ");
    scanf("%f", &n);
    printf("temperature in kelvin: %f\n", n + 273.15);
    printf("temperature in farengeith: %f\n", (n*9/5)+ 32);
    return 0;
}
