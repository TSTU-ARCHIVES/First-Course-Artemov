
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

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

int main() {
    printf("input source file name: ");
    char* name = inp();
    FILE* f;
    if ((f = fopen(name,"rb")) < 0) {
        fprintf(stderr, "error while reading source file");
        return 1;
    }

    printf("input result file name: ");
    char* rname = inp();
    FILE* rf;
    if ((rf = fopen(rname,"wb")) < 0) {
        fprintf(stderr, "error while reading source file");
        return 1;
    }

    char t;

    char key;
    printf("input key: ");
    scanf("%c", &key);

    while (fread(&t, 1, 1, f) > 0) {
        t ^= key;
        fprintf(rf, "%c", t);
    }

    fclose(f);
    return 0;
}
