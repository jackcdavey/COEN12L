#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "set.h"

#define EMPTY 0
#define FILLED 1
#define DELETED 2

struct set{
    char **data;
    char *flags;
    int count;
    int length;
};

SET *createSet(int maxElts){
    SET *sp;
    sp = malloc(sizeof(SET));
    int i;
    assert(sp != NULL);
    sp->length = maxElts;
    sp->count = 0;
    sp->data = malloc(sizeof(char*)*maxElts);
    assert(sp->data != NULL);
    sp->flags = malloc(sizeof(char*)*maxElts);
    for(i = 0; i < maxElts; i++)
        sp->flags[i] = EMPTY;
    assert(sp->flags != NULL);
    return(sp);
}

void destroySet(SET *sp){
    assert(sp != NULL);
    for(int i = 0; i < sp->count; i++)
        free(sp->data[i]);
    free(sp->flags);
    free(sp->data);
    free(sp);
}

int numElements(SET *sp){
    if(!sp)
        return 0;
    return(sp->count);
}

unsigned strhash(char *s){
    unsigned hash = 0;

    while(*s != '\0')
        hash = 31 * hash + *s ++;
    return hash;
}

static int search(SET *sp, char *elt, bool *found){
    assert(sp != NULL);
    assert(elt != NULL);
    int index = (strhash(elt))%(sp->length);
    if(sp->flags[index] == EMPTY){
        *found = false;
        return index;
    }
    int initDel = -1;
    while(sp->flags[index] != EMPTY){
        if(strcmp(sp->data[index], elt) == 0 && sp->flags[index] != DELETED){
            *found = true;
            return index;
        }
        if(sp->flags[index] == DELETED && initDel == -1)
            initDel = index;
        index = (index + 1) % (sp->length);
    }
    *found = false;
    if(initDel != -1)
        index = initDel;
    return index;
}

void addElement(SET *sp, char *elt){
    assert(sp != NULL);
    assert(elt != NULL);
    bool found = true;
    if(sp->count == sp->length)
        return;
    int index = search(sp, elt, &found);
    if(found == false){
        sp->data[index] = strdup(elt);
        sp->flags[index] = FILLED;
        sp->count++;
        return;
    }
    else
        return;
}

char **getElements(SET *sp){
    assert(sp != NULL);
    int j=0;
    char **dup;
    dup = malloc(sizeof(char*)*sp->count);
    assert(dup != NULL);
    for(int i = 0; i<sp->length; i++){
        if(sp->flags[i] == FILLED){
            dup[j] = strdup(sp->data[i]);
            j++;
        }
    }
    return dup;
}

void removeElement(SET *sp, char *elt){
    assert(sp != NULL);
    assert(elt != NULL);
    bool found;
    int pos = search(sp, elt, &found);
    if(found){
        free(sp->data[pos]);
        sp->flags[pos] = DELETED;
        sp->count--;
    }
    else
        return;
}

char *findElement(SET *sp, char *elt){
    assert(sp != NULL);
    bool found;
    int index = search(sp, elt, &found);
    if(found == false)
        return(NULL);
    return(sp->data[index]);
}

