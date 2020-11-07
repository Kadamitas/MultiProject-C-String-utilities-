#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int ArraySize; // I'd loop till NULL but this is safer and on the sheet it doesnt say I can't use globals

void printlist(char** data){ 
    for(int i = 0; i<ArraySize; i++){
        printf("%s ", data[i]);
    }
}
char* toUniform(char str[]){
    int upperORlower = 0;
    char * uniform = (char*) malloc(sizeof(char));
    char add;

    for(int j = 0; j<strlen(str); j++){
        //check if upper/lower and set this as default
        if(str[j] > 64 && str[j] < 91 && upperORlower == 0){
            upperORlower = 1;
        }
        if(str[j] > 96 && str[j] < 123 && upperORlower == 0){
            upperORlower = 2;
        }
        //changes to upper or lower depending on which came first or doesn't
        if(upperORlower == 2){
            add =(tolower(str[j]));
        }else if(upperORlower == 1){
            add =(toupper(str[j]));
        }else{
            add =(str[j]);
        }

            //make array hold it
        if(realloc(uniform, sizeof(uniform)+sizeof(add)) != NULL){
            uniform = realloc(uniform, sizeof(uniform)+sizeof(add));
            uniform[j] = add;
        }else{
            printf("Couldn't realloc uniform :( \n");fflush(stdout);
            return NULL;
        }
    }
    return uniform;
}

int main(int b, char** a) {
    char ** stringArray = (char**) malloc(sizeof(char *) +1);

    for(int i = 1; i<b;i++){
        stringArray[i-1] = malloc( sizeof(char) * sizeof(toUniform(a[i-1]) +1));
        stringArray[i-1] = toUniform(a[i]);
        if(stringArray == NULL){
            printf("Ruh roh raggy, bad allocation");
            return 1;
        }
   }
    ArraySize = b-1;
    printlist(stringArray);

    printf("\n");
    free(stringArray);
    return 0;
}