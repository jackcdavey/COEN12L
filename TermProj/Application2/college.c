#include "info.h"

int main(){
    srand(time(NULL));
    
    //code to generate 1000 random students
    SET *sp=createDataSet(MAX);
    int prev=0;
    for(int i=0; i<=1000; i++){
        int id=((rand()%2)+1);
        int age=((rand()%13)+18);
        id+=prev;
        prev=id;
        insertion(sp, age, id);
    }
    
    //code to run all functions
    int a=((rand()%13)+18), n=((rand()%3000)+1);
    //insertion(sp, a, n);
    searchID(n, sp);
    deletion(sp, n);

    destroyDataSet(sp);
}
