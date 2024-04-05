#include "elements.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************
 *
 *  DEFAULT PRINT FUNCTIONS
 *
 ***************************************
 */


int char_print(FILE *fp, const void *p) {
  char c;
  if (!fp || !p) {
    fprintf(stderr, "Wrong arguments to function %s\n", __func__);
    return -1;
  }
  c = *(char *)p;
  return fprintf(fp, "%c ", c);
}

int string_print(FILE *fp, const void *p) {
  char* str;
  if (!fp || !p) {
    fprintf(stderr, "Wrong arguments to function %s\n", __func__);
    return -1;
  }
  str = (char *)p;
  return fprintf(fp, "%s ", str);
}


int int_print(FILE *fp, const void *p) {
  if (!fp || !p) {
    fprintf(stderr, "Wrong arguments to function %s\n", __func__);
    return -1;
  }
  return fprintf(fp, "%d ", *((int *)p));
}

/*****************************************************************************
 *
 *  COMPARISON FUNCTIONS
 *
 *  Functions of type compare_elem_fn, i.e.
 *  int (*cmp) (const void* elem1, const void* elem2)
 *****************************************************************************

 */
 int int_cmp(const void *elem1, const void *elem2)
{


    if (*(int *)elem1 > *(int *)elem2)
    {
        return 1;
    }
    if (*(int *)elem2 > *(int *)elem1)
    {
        return -1;
    }
    return 0;
}

int str_cmp(const void *elem1, const void *elem2){
    return strcmp((char*)elem1, (char*)elem2);
}

