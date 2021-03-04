#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAX 3000

typedef struct set SET;

SET* createDataSet(int maxStu);
void destroyDataSet(SET *sp);
int searchID(int idNum, SET *sp);
void insertion(SET *sp, int age, int id);
void deletion(SET *sp, int id);
