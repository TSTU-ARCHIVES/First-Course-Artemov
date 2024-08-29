#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char* inp(void) {
    char * buffer = NULL;              
    int capacity = 0;          
    int n = 0;                    
    int ch;                             

    while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
        if (n+1 > capacity) { 
            if ( !capacity ) capacity = 32; 
            else if (capacity <= 2048) capacity += capacity;
            else { 
                free(buffer);
                return NULL;
            }
            char * temp = (char*)realloc(buffer, capacity * sizeof(char));
            if ( !temp ) {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
        buffer[n++] = ch;   
    }
    if (n == 0 && ch == EOF) return NULL; 
 
    char* minimal = (char*) malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);                           
    minimal[n] = '\0';                      
    return minimal;
}

void swap(int* arr, int a, int b) {
    int t = arr[b];
    arr[b] = arr[a];
    arr[a] = t;
    return;
}

int* bub(int* arr, int ln) {
    for (int j = 1; j<ln; j++) {
        for (int i = 0; i<ln-j; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr, i, i+1);
            }
        }
    }
    return arr;
}

void Heapify(int* M, int N, int i)
        {
            int iM = i;
            int L = 2 * i + 1, R = 2 * i + 2;
            if (L<N && (M[L] > M[iM]))
            {
                iM = L;
            }
            if (R < N && (M[R] > M[iM]))
            {
                iM = R;
            }
            if (i != iM)
            {
                swap(M, i, iM);
                Heapify(M, N, iM);
            }
            return;
        }
    
int* HeapSort(int* M, int N)
        {
            for (int i = N/2 - 1; i>=0; i--)
            {
                Heapify(M, N, i);
            }
            for (int i = N - 1; i>=0;i--)
            {
                swap(M, 0, i);
                Heapify(M, i, 0);
            }
            return M;
        }

int main(){
    int* arr = malloc(2*sizeof(int));
    char* arv; 
    char* arb; 
    int* msc;
    int* mss;
    int i = 0;
    FILE *f1, *f2;
    clock_t bub_srt_strt;
    clock_t bub_srt_end;
    clock_t h_srt_strt;
    clock_t h_srt_end;

    printf("input source file name: ");
    arv = inp(); 
    printf("input result file name: ");
    arb = inp(); 

    if ((f1 = fopen(arv, "rb")) == 0 || (f2 = fopen(arb, "wb"))==0 ) {
        fprintf(stderr, "Error %s while reading file", strerror(errno));
        return 1;
    }
    
    while (fscanf(f1, "%d", &arr[i]) != EOF)
    {
        i++;
        arr = realloc(arr, (2+i)*sizeof(int));
    }
    
    arr[i] = '\0';
    fclose(f1);

    bub_srt_strt = clock();
    msc = bub(arr,i);
    bub_srt_end = clock();
    printf("bubble sort took %f seconds", (double)(bub_srt_end-bub_srt_strt)/CLOCKS_PER_SEC );
    fprintf(f2, "bubble sort\n");
    for (int j = 0; j<i; j++) {
        fprintf(f2, "%d\n", msc[j]);
    }

    h_srt_strt = clock();
    mss = HeapSort(arr,i);
    h_srt_end = clock();
    printf("\npyramidal sort took %f seconds", (double)(h_srt_end-h_srt_strt)/CLOCKS_PER_SEC );
    fprintf(f2, "pyramidal sort\n");
    for (int j = 0; j<i; j++) {
        fprintf(f2, "%d\n", mss[j]);
    }
    
    fclose(f2);
    return 0;
}
