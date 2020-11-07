#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int b, char** a) {
    if(b!=4){
        printf("an error message and stop running.  You will also have to make sure you properly convert the second command line argument to an integer that C can manipulate, since by default, command line arguments are saved as strings.  The function of this program will be to insert the second string into the first string, with the input integer being the index where the string should be inserted.  For example, if the user calls the program like this:  ./my_program “aaa” 1 “bbbb” then the new string would look like “abbbbaa”.Once the new string has been formed, the program is to print the new string to the terminal.  A few important things to keep in mind for this program is that dynamic memory allocation will be needed to store the new string.  One of the tricky problems to solve for this question is figuring out how much space the new string needs. Remember that all valid C strings end in a null character!  In addition, you are not allowed to use strlen() and strncpy().  If you need the functionality of either of those two functions, then it is required that you implement your own versions of them.  They should be called string_length() and string_n_copy() respectively and they should function the same as the original functions.  That is, they should take in the same parameters and produce the same output.  It is a good idea to consult the manual pages for strlen() and strncpy().  Also note that if the user inputs an index that is out of bounds of the first string, a segmentation fault will occur. Your program should be able to prevent this from happening by checking the user input and exiting with an error message if the index is out of bounds");
        return 1;
    }

    char* input1 = a[1];
    int input2 = atoi(a[2]);
    char* input3 = a[3];
    char* string = malloc(sizeof(char));

    int input1Size=0;
    for(; input1[input1Size] != '\0'; input1Size++){
    }
    int input3Size=0;
    for(; input3[input3Size] != '\0'; input3Size++){
    }

    if(input2 > input1Size){
        printf("error message \n");
        return EXIT_FAILURE;
    }
    for(int i = 0; i<input2;i++){
        char charString[2] = {input1[i], '\0'};
        if(realloc(string, sizeof(string) +1) != NULL){
            string = realloc(string, sizeof(string) +1);
        }else{
            printf("oopise not enough space\n");
            return 1;
        }
        string = strcat(string,charString);

    }

    if(realloc(string, sizeof(string) + input3Size) != NULL){
            string = realloc(string, sizeof(string)+ input3Size);
        }else{
            printf("oopise not enough space\n");
            return 1;
        }
    strcat(string,input3);

    for(int i = input2; input1[i] != '\0';i++){
        char charString[2] = {input1[i], '\0'};
        if(realloc(string, sizeof(string) +1) != NULL){
            string = realloc(string, sizeof(string) +1);
        }else{
            printf("oopise not enough space\n");
            return 1;
        }
        string = strcat(string,charString);
    }

    printf("%s\n",string);
  return 0;
}