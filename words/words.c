#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main( int argc, char *argv[] ) {

    int startingIndex = 1;

    if (argc==1) {
        char c;
        while ((c = fgetc(stdin)) != EOF) {
            if (!isalpha(c)) {
                printf("\n");
            }
            else {
                printf("%c", c);
            }
        }
        printf("\n");
    }

    else if (argc>1) {
        for (int j=0; j<argc; j++) {
            int res;
            res = strcmp("-", argv[j]);
            if (res==0) {
                startingIndex = j + 1;
            }
        }
        for (int i=startingIndex; i<argc; i++) {
            FILE* filePointer;
            char* fileName = argv[i];
            filePointer = fopen(fileName, "r");
            if (filePointer != NULL) {
                char c;
                while ((c = fgetc(filePointer)) != EOF) {
                    if (!isalpha(c)) {
                        printf("\n");
                    }
                    else {
                        printf("%c", c);
                    }
                }
                printf("\n");
            }
            else {
                fprintf(stderr, "File not found");
                return 1;
            }
        }
    }

    return 0;
}