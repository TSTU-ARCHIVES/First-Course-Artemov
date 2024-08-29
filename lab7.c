
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char* inp(FILE* f) {
    char * buffer = NULL;              
    int capacity = 0;          
    int n = 0;                    
    int ch;                             

    while ((ch = fgetc(f)) != EOF && ch != '\n') {
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

int isLetter(char a) {
    if (((int)a >=65 && (int)a <=90) || ((int)a >=97 && (int)a <= 122) ) {
        return 1;
    }
    return 0;
} 

int isSameLetter(char a, char b) {
    if (isLetter(a) && isLetter(b) ) {
        if (abs((int)a - (int)b) == 32) {
            return 1;
        }
    }
    return 0;
}

int isSpace(char a) {
    if ((int)a == 32) {
        return 1;
    }
    return 0;
}

int main() {
    printf("input file name: ");
    char* name = inp(stdin);
    FILE* f;
    if ((f = fopen(name,"rb")) < 0) {
        fprintf(stderr, "error while reading file");
        return 1;
    }

    printf("input mode(0..1): ");
    int mode;
    if (scanf("%d", &mode) < 0) {
        fprintf(stderr, "error while reading mode");
        return 1;
    };
    if (mode !=0 && mode !=1) {
        fprintf(stderr, "incorrect mode");
        return 1;
    }
    char* str = inp(f);
    char symbls[strlen(str)];
    int n = 0;
    if (mode == 0) {
        for (int i = 0; i<strlen(str); i++) {
            if ((strchr(symbls, str[i]) == NULL) && !isSpace(str[i])) {  
                symbls[n] = str[i];
                n++;
            };
    }
    }
    if (mode == 1) {
        for (int i = 0; i<strlen(str); i++) {
            int copycreated = 0;
            for (int j = 0; j<n; j++) {
                if (isSameLetter(symbls[j], str[i])) {
                    copycreated = 1;
                }
            }
            if ((strchr(symbls, str[i]) == NULL) && copycreated == 0 && !isSpace(str[i])) {  
                symbls[n] = str[i];
                n++;
                continue;
            }
                
        }    
    }

    int c;
    
    for (int i = 0; i<n; i++) {
        c =0 ;
        for (int j = 0;j<strlen(str); j++) {
            if ((mode == 0 && symbls[i] == str[j]) || 
                (mode == 1 && (isSameLetter(symbls[i], str[j]) || symbls[i] == str[j]))
               ) {
                c++;
            }
        }
        printf("%c - %d\n", symbls[i], c);
    }


    return 0;
}
