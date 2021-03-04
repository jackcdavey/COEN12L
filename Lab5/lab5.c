#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50
#define MAX_ELTS 10000

typedef struct element{
    int num;
    char name[20];
}ELE;


void insertionSort(ELE arr[], int len);
void merge(ELE arr[], int l, int m, int h);
void mergeSort(ELE arr[], int l, int h);
void testPrint(ELE arr[], int len);



int main(int argc, char **argv){
    char ch;
    int count=0;
    FILE *f = fopen(argv[1], "r");
    ELE *entries = malloc(sizeof(ELE) * MAX_ELTS);
    if(f){
        int length=0;
        while(fscanf(f, "%d %s\n", &(entries[length].num), (entries[length].name)) != EOF)
            length++;
        printf("length is %d\n", length);
        //insert all elements into an array
        int pos=0, n=-1;
        while(fscanf(f, "%d %s\n", &(entries[pos].num), (entries[pos].name) )!=EOF)
            pos++;
        printf("old:\n");
        testPrint(entries, length);
        
        int input=0;
        
        
        printf("1: Perform Insertion Sort \n2: Perform Merge Sort\n");
        scanf("%d", &input);
        int time=0;
        switch (input) {
            case 1:
                time = clock();
                insertionSort(entries, length);
                time = (clock() - time);
                printf("\n new:\n");
                testPrint(entries, length);
                printf("Sorted in: %d\n", time);
                break;
            case 2:
                time = clock();
                mergeSort(entries, 0, length-1);
                time = (clock() - time);
                printf("\n new:\n");
                testPrint(entries, length);
                printf("Sorted in: %d\n", time);

            case 3:
                testPrint(entries, length);
            default:
                break;
        }
    }
    else
            printf("Failed to open file\n");
}



//INSERTION SORT
//O(n^2)
void insertionSort(ELE entries[], int len){
    int z;
    ELE key = entries[0];
    for(int x = 1; x < len; x++){
        key = entries[x];
        z=x-1;
        while(z>= 0 && entries[z].num > key.num){
            entries[z+1] = entries[z];
            z--;
        }
        entries[z + 1] = key;
    }
    return;
}
//INSERTION SORT



//MERGE SORT
//O(n)
void merge(ELE arr[], int l, int m, int h){
    printf("one\n");
    int arr1Sz=m-l+1;
    int arr2Sz=h-m;
    ELE *first = malloc(sizeof(ELE)*arr1Sz), *second = malloc(sizeof(ELE)*arr2Sz);
     printf("two\n");
    int firstPos=0, secondPos=0, thirdPos=l;
    while(firstPos<arr1Sz){
        first[firstPos] = arr[firstPos+l];
        firstPos++;
    }
    while(secondPos<arr2Sz){
        second[secondPos] = arr[secondPos+m+1];
        secondPos++;
    }
    printf("three\n");
    firstPos=0, secondPos=0;
    printf("l is %d m is %d h is %d\n", l, m, h);
    while(firstPos < arr1Sz && secondPos < arr2Sz){
        printf("inside\n");
        printf("First is %d, second is %d\n", firstPos, secondPos);
        if(first[firstPos].num<=second[secondPos].num){
            arr[thirdPos] = first[firstPos];
            thirdPos++, firstPos++;
        }else{
            arr[thirdPos] = second[secondPos];
            thirdPos++, secondPos++;
        }
    }
    printf("four\n");
    while(firstPos<arr1Sz){
        arr[thirdPos] = first[firstPos];
        thirdPos++, firstPos++;
    }
    while(secondPos<arr2Sz){
        arr[thirdPos] = second[secondPos];
        thirdPos++, firstPos++;
    }
    
    //Okay im very confused by this... without this ^ print statement, the program returns a segmentation fault after running merge sort. With the statement, however, the code executes, and prints out random garbage. ????
    free(first);
    free(second);
    return;
}

void mergeSort(ELE arr[], int l, int h){
    int x;
    if(l<h){
        x = l + (h - l) / 2;
        mergeSort(arr, l, x);
        mergeSort(arr, x + 1, h);
        merge(arr, l, x, h);
    }
    return;
}
//MERGE SORT

//O(n)
void testPrint(ELE arr[], int len){
    int pos=0;
    while(pos <= len && arr[pos].num!=0){
        printf("%d %s\n", arr[pos].num, arr[pos].name);
        pos++;
    }
}
