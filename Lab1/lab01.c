#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30

int main(int argc, char **argv){
    char ch;
    int count=0;
    //int prevCharWasSpecial=0;
    FILE *f = fopen(argv[1], "r");
    if(f){
        while((ch=getc(f))!=EOF){
            if(ch == ' ' || ch == '\n')
                count++;
        }
        printf("%d total words\n", count+1);
    }
    else{
            printf("Failed to open file\n");
    }
}
