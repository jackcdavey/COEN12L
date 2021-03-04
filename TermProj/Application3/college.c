#include "info.h"

int main(){
    srand(time(NULL));
    
    //code to generate 1000 random students
    LIST *lp;
    lp=createDataSet();
    //printf("Pass\n");
    int prev=0;
    for(int i=0; i<=1000; i++){
        //printf("One\n");
        int id=((rand()%2)+1);
        int age=((rand()%13)+18);
        id+=prev;
        prev=id;
        insertion(lp, age, id);
    }
    printf("huh");
    int a=((rand()%13)+18), n=((rand()%3000)+1);
    //insertion(sp, a, n);
    searchID(n, lp);
    searchAge(a, lp);
    deletion(lp, n);
    int gap = maxAgeGap(lp);
    printf("The largest age gap is %d\n", gap);
    destroyDataSet(lp);
}
