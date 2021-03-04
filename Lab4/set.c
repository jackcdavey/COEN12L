#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "set.h"

struct set{
    int (*compare)();
    int count;
    int length;
    unsigned(*hash)();
    LIST **lists;
};

SET *createSet(int maxElts, int (*compare)(), unsigned (*hash)()){
    assert(maxElts>0);
    assert(compare!=NULL);
    assert(hash!=NULL);
    SET *sp;
    sp = malloc(sizeof(SET));
    assert(sp !=NULL);
    sp->count = 0;
    sp->length = maxElts;
    sp->lists = malloc(sizeof(void *)*sp->length);
    sp->compare = compare;
    sp->hash = hash;

    for(int i = 0; i < sp->length; i++){
        sp->lists[i] = createList(compare);
    }

    assert(sp->lists != NULL);
    return sp;
}

void destroySet(SET *sp){
    free(sp->lists);
    free(sp);
}

int numElements(SET *sp){
    assert(sp != NULL);
    return(sp->count);
}


void addElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL);
    int idx = (*sp->hash)(elt)%sp->length;
    if(findItem(sp->lists[idx],elt) == NULL){
        addFirst(sp->lists[idx], elt);
        sp->count++;
    }
} 


void removeElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL);
    int idx = (*sp->hash)(elt)%sp->length;
    if(findItem(sp->lists[idx], elt) != NULL){
        removeItem(sp->lists[idx], elt);
        sp->count--;
    }
}

void *findElement(SET *sp, void *elt){
    assert(sp != NULL && elt != NULL);
    int idx = (*sp->hash)(elt)%sp->length;
    return(findItem(sp->lists[idx], elt));
}

void *getElements(SET *sp){
    assert(sp != NULL);
    void **arr;
    void **copy;
    int count = 0;
    arr = malloc(sizeof(void*)*sp->count);
    for(int i = 0; i < sp->length; i++){
        copy = getItems(sp->lists[i]);
        for(int j = 0; j< numItems(sp->lists[i]); j++){
            arr[count] = copy[j];
            count++;
        }
    } 
    return arr;
}
