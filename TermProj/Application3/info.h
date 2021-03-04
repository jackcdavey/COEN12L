#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef struct student STU;
typedef struct list LIST;


LIST* createDataSet();
void destroyDataSet(LIST *lp);
int searchID(int idNum, LIST *lp);
int searchAge(int age, LIST *lp);
void insertion(LIST *lp, int age, int id);
void deletion(LIST *lp, int id);
int maxAgeGap(LIST *lp);
