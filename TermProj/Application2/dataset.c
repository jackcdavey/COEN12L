#include "info.h"

struct set{
    int numStudents;
    int maxStudents;
    int *flags;
    int *age;
    int *id;
};

//O(n)
//Creates a set of students
SET* createDataSet(int maxStu){
    SET *sp=malloc(sizeof(SET));
    assert(sp != NULL);
    
    sp->id=malloc(sizeof(int)*maxStu);
    sp->age=malloc(sizeof(int)*maxStu);
    sp->flags=malloc(sizeof(int)*maxStu);
    
    sp->numStudents=0;
    sp->maxStudents=maxStu;
    
    for(int i=0; i<=maxStu; i++)
        sp->flags[i]=0;
    
    printf("dataset created\n");
    return sp;
}

//O(1)
//Frees entire set
void destroyDataSet(SET *sp){
    free(sp);
    free(sp->id);
    free(sp->age);
    free(sp->flags);
    printf("Set destroyed \n");
    return;
}

//O(1)
//Checks the id pos in flags array, returns 1 if found, 0 otherwise
int searchID(int idNum, SET *sp){
    if(sp->flags[idNum]){
        printf("Student %d exists\n", idNum);
        return 1;
    }else{
        printf("Student %d does not exist\n", idNum);
        return 0;
    }
}

//O(1)
//Adds a student to set given an age and ID
void insertion(SET *sp, int age, int id){
    if(sp->flags[id]){
        printf("ID number already exists \n");
        return;
    }
    sp->flags[id]=1;
    sp->age[id]=age;
    sp->id[id]=id; //i now realize this is redundant but oh well lol
    sp->numStudents++;
    printf("Age: %d ID: %d was inserted into the list \n", age, id);
    return;
}

//O(1)
//Searches for student based on ID, removes if found
void deletion(SET *sp, int id){
    if(searchID(id, sp)){
        sp->flags[id]=0;
        sp->numStudents--;
        printf("Student with ID %d removed\n", id);
    }else{
        printf("ID %d does not exist\n", id);
        return;
    }
}
