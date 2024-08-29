#include <stdio.h>
#include <string.h>
void reverse(char *x)
{
    char t;
    int  n= 0;
    for (int i = strlen(x) - 1; i > n; i--)
    {
        t = x[i];
        x[i] =x[n];
        x[n] = t;
        n++;
    }
}

int tobin(int x) {
    long b = 0;
    int i = 1;
    while (x > 0) {
    b += (x%2) * i;
    i *= 10;
    x /= 2;
    }
    return b;
}

int tooct(int x) {
    long b = 0;
    int i = 1;
    while (x > 0) {
    b += (x%8) * i;
    i *= 10;
    x /= 8;
    }
    return b;
}

void tohigher(int x, int mode) {
    char alf[36] = {'0', '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char res[50];
    int i = 0;
    printf("\n%d", x);
    while(x>0) {
        res[i] = alf[x%mode];
        x /= mode;
        i++;
    }
    reverse(res);
    printf(" in %d = %s", mode, res);
}

int main() {
    int n;
    printf("input number: ");
    scanf("%d",&n);
    printf("\n%d in binary = %d", n, tobin(n));
    printf("\n%d in oct = %d", n, tooct(n));
    tohigher(n, 16);
    tohigher(n, 36);
    return 0;
}
