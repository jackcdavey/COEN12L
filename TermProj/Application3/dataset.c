#include "info.h"

struct student{
    int age;
    int id;
    STU *next;
    STU *prev;
};

struct list{
    STU *head;
    STU *tail;
    int num;
};

//O(1)
//Creates an empty list for students
LIST* createDataSet(){
    LIST *lp=malloc(sizeof(LIST));
    assert(lp);

    lp->head=malloc(sizeof(STU));
    lp->head=NULL;
    lp->tail=lp->head;
    lp->num=0;
    
    printf("dataset created\n");
    return lp;
}

//O(n)
//Frees entire list
void destroyDataSet(LIST *lp){
    assert(lp);
    STU *sp=lp->head;
    STU *np=sp->next;
    if(!(sp->next)){
        free(sp);
        return;
    }
    
    while(np){
        free(sp);
        sp=np;
        np=np->next;
    }
    
    printf("Set destroyed \n");
    return;
}

//O(n)
//Checks the id pos in flags array, returns 1 if found, 0 otherwise
int searchID(int idNum, LIST *lp){
    STU *sp=lp->head;
    while(sp){
        if(sp->id==idNum){
            printf("Student with ID %d found\n", idNum);
            return 1;
        }
        sp=sp->next;
    }
    printf("Student with ID %d does not exist", idNum);
    return 0;
}

//O(n)
//Searches list for students with matching age, returns number of students found
int searchAge(int age, LIST *lp){
    STU *sp=lp->head;
    int numStu=0;
    while(sp){
        if(sp->age==age){
            printf("Student %d is %d years old\n", sp->id, age);
            numStu++;
        }
    }
    printf("There are %d %d year old students\n", numStu, age);
    return numStu;
}

//O(n)
//Adds a student to list given an age and ID
void insertion(LIST *lp, int age, int id){
    assert(lp);

    STU *sp = malloc(sizeof(STU));
    STU *np = lp->head;
    STU *pp = lp->head;
    

    sp->age = age, sp->id = id;
    //printf("a\n");

    if(lp->head == NULL){
        //printf("b\n");
        lp->head=sp;
        lp->tail=sp;
        lp->num++;
    }else{
        while(np->next){
            if(age <= np->next->age){
                sp->next = np->next;
                sp->prev = np;
                np->next = sp;
                np = sp;
                return;
            }
            np=np->next;
        }
    }
    printf("Student with age %d and ID %d was inserted\n", age, id);
    return;
}

//O(n)
//Searches for student based on ID, removes if found
void deletion(LIST *lp, int id){
    assert(lp);
    STU *sp = lp->head;
    while(sp){
        if(sp->id == id){
            sp->prev->next = sp->next;
            sp->next->prev = sp->prev;
            printf("Student with ID %d was removed\n", id);
            return;
        }else
            sp=sp->next;
    }
    printf("Student with ID %d does not exist\n", id);
    return;
}

//O(1)
//Computes the largest age gap by subtracting tail age from head age (List is sorted by age)
int maxAgeGap(LIST *lp){
    int low = lp->head->age;
    int high = lp->tail->age;
    int gap = high-low;
    printf("The largest age gap is %d", gap);
    return gap;
}
