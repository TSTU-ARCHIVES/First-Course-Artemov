
#include <stdio.h>
int sumofdigs(int x, int mode) {
    int res = 0;
    while(x>0) {
        if (mode == 0) {
            res+=x%10;
            x /= 10;
            continue;
        }
        if (mode == 1) {
            if (x%2==1) {
                res+=x%10;
            }
            x /= 10;
            continue;
        }
        if (mode == 1) {
            if (x%2==0) {
                res+=x%10;
            }
            res+=x%10;
            x /= 10;
            continue;
        }
    }
    return res;
}

int maxdigit(int x) {
    int t = -1;
    while (x>0) {
        if (x%10 > t) {
            t = x%10;
        }
        x/=10;
    }
    return t;
}

int mindigit(int x) {
    int t = 10;
    while (x>0) {
        if (x%10 < t) {
            t = x%10;
        }
        x/=10;
    }
    return t;
}

int main() {
    int n;
    printf("input number: ");
    if ( scanf("%d", &n) > 0) {
        printf("\nsum of digits = %d\n", sumofdigs(n, 0));
        printf("max digit = %d\n", maxdigit(n));
        printf("minimal digit = %d\n", mindigit(n));
        printf("sum of odd digits = %d\n", sumofdigs(n, 1));
        printf("sum of even digits = %d\n", sumofdigs(n, 2));
        return 0;
    } else {
        fprintf(stderr, "incorrect input");
        return 1;
    }
    
}
