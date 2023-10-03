#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void decoding(char *str){
    char *ptr = str;
    char *begin, *end;
    begin = str;
    end = NULL;

    while(1){
        if (isalpha(*ptr)){ //CHECK THIS ***********
            //change to upper case
        } else{
            //set begin and end
            //reverse the word
            //break the loop
        }
    }
}

int main(){
    FILE *fin, *fout;
    fin = fopen("lab1p3in", "r");
    if (!fin){
        printf("Input file does not exist.\n");
        return 0;
    }

    fout = fopen("lab1p3out", "w");
    if (!fout){
        printf("Output file does not exist.\n");
        return 0;
    }

    char temp[100];

    while(fgets(temp, 100, fin) != NULL){
        decoding(temp);
        fprintf(fout, temp);
    }

    fclose(fin);
    fclose(fout);
    return 1;
}

