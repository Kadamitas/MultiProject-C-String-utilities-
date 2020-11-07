#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int b, char** a) {
    int upperORlower = 0;
    char * uniform = (char*) malloc(sizeof(char));
    char add;

    if(b <= 1){ // no arguments then bust
        return 1;
    }

    for(int i = 1; i<b;i++){
        for(int j = 0; j<strlen(a[i]); j++){

            //check if upper/lower and set this as default
            if(a[i][j] > 64 && a[i][j] < 91 && upperORlower == 0){
                upperORlower = 1;
            }
            if(a[i][j] > 96 && a[i][j] < 123 && upperORlower == 0){
                upperORlower = 2;
            }

            //changes to upper or lower depending on which came first or doesn't
            if(upperORlower == 2){
                add =(tolower(a[i][j]));
            }else if(upperORlower == 1){
                add =(toupper(a[i][j]));
            }else{
                add =(a[i][j]);
            }

            //make array hold it
            if(realloc(uniform, sizeof(uniform)+sizeof(add)) != NULL){
                uniform = realloc(uniform, sizeof(uniform)+sizeof(add));
                uniform[j] = add;
            }else{
                printf("Segmentation fault (core dumped)");fflush(stdout);
                return 1;
            }

        }
        printf("%s",uniform);
        printf("\n");
        upperORlower = 0;
        memset(uniform, 0, sizeof(uniform)*strlen(uniform)-1);
        //this makes the array be able to reuse the memory by clearing it
        //oof I didn't read the next assignment,
        //doing this again but 2D since this already reads all inputs
    }
    free(uniform);
    return 0;
}