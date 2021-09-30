#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// main function
int main( int argc, char *argv[] ) {

    int startingIndex = 1;

    // if arg count is 1
    if (argc==1) {
        char c;
        // takes standard in
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

    // if arg count is greater than 1
    else if (argc>1) {
        for (int i=startingIndex; i<argc; i++) {
            int res;
            res = strcmp("-", argv[i]);
            // if argument is a special filename
            if (res==0) {
                char c;
                while ((c = fgetc(stdin)) != EOF) {
                    // if the character is not an alphabet letter
                    if (!isalpha(c)) {
                        printf("\n");
                    }
                    // if the character is an alphabet letter
                    else {
                        printf("%c", c);
                    }
                }
                printf("\n");
            }
            // if argument is not a special filename
            else {
            FILE* filePointer;
            char* fileName = argv[i];
            filePointer = fopen(fileName, "r");
            // if file does exist
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
            // if file does not exist
            else {
                fprintf(stderr, "File not found");
                return 1;
            }
            }
        }
    }
    return 0;
}