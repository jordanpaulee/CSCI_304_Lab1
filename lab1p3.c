#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void decoding(char *str){
    char *ptr = str;
    char *begin, *end;
    begin = str;
    end = NULL;

    while(1){
        if (isalpha(*ptr)){
            //change to uppercase
            if (islower(*ptr)){
                *ptr = toupper(*ptr);
            }
        } else{
            //set begin and end
            end = ptr - 1;

            //reverse the word
            while (begin < end) {
                char temp = *begin;
                *begin = *end;
                *end = temp;
                begin++;
                end--;
            }

            if(*ptr == '\0' || *ptr == '\n'){
                break;
            }
            else{
                *ptr = ' ';
            }
            begin = ptr+1;
            end = NULL;
            //break the loop
        }
        ptr++;
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

