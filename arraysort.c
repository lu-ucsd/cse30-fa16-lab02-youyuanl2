#include <stdio.h>
#include <stdlib.h>

#include "arraysort.h"
/**
 * This function creates an empty list, with space allocated for an array of
 * maxElements ints (pointed to by int *sortedList) and returns a pointer to the
 * list.
 */
list* createlist(int maxElements) {
  /* use malloc() to create a new list */
  list * newList;
  int * newArr;

  if (maxElements <= 0) // invalid input
    return NULL;

  newList = malloc(sizeof(list)); // try to malloc a new list

  if (newList == NULL) // malloc fails
    return NULL;

  newArr = malloc(maxElements * sizeof(int)); // try to malloc a new array

  if (newArr == NULL) { // malloc fails
    free(newList);
    newList = NULL;
    return NULL;
  }

  // initialize all three member variables of the new list
  newList->sortedList = newArr;
  newList->size = 0;
  newList->maxSize = maxElements;

  return newList;
}

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should insert the value 'val' into sortedList, update the number of elements
 * in the list and return the index where the element was inserted. If the list
 * is full before inserting the element, it should increase the size of the list
 * to double its previous size and then insert the element. If the result of the
 * insert was not successful it should return -1. Note that the resulting list
 * should be sorted and there should be no information loss. The function should
 * return -1 if no valid list was passed to it..
 */
int insert(list *ls, int val) {
  /* insert the input value into sortedList */
  int i = 0, j, * doubled;

  if (ls == NULL || (ls->sortedList) == NULL || val < 0) // invalid input
    return -1;

  if ((ls->size) == (ls->maxSize)) { // when sortedList is full
    doubled = realloc(ls->sortedList, (ls->maxSize) * 2 * sizeof(int));
    if (doubled != NULL) { // resize succeeds
      ls->sortedList = doubled;
      ls->maxSize *= 2;
      doubled = NULL;
    } else // resize fails
      return -1;
  }

  while ((i < (ls->size)) && (val > (ls->sortedList)[i])) // find position
    i++;

  for (j = ls->size; j > i; j--) // make space for the input value
    (ls->sortedList)[j] = (ls->sortedList)[j-1];

  (ls->sortedList)[i] = val; // insert the input value
  (ls->size)++; // update size

  return i;
}

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should delete all instances of elements in the sortedList with value 'val',
 * update the number of elements remaining in the list and return the number of
 * elements that were deleted. Once again the resulting list should be sorted.
 */
int remove_val(list *ls, int val) {
  /* remove all occurence of the input value from sortedList */
  int count, i;
  count = i = 0;

  // find the first occurence of the input value in sortedList
  while ((i < (ls->size)) && (val != (ls->sortedList)[i]))
    i++;

  if (i == (ls->size)) // when the input value is not in sortedList
    return 0;
  else { // when the input value is in sortedList
    i++;
    count = 1;
  }

  // find all occurence of the input value in sortedList
  while ((i < (ls->size)) && (val == (ls->sortedList)[i])) {
    i++;
    count++;
  }

  // remove all occurence of the input value in sortedList
  for (; i < (ls->size); i++)
    (ls->sortedList)[i-count] = (ls->sortedList)[i];

  ls->size -= count; // update size
  return count;
}

/**
 * This function takes a pointer to the the list as input and returns the
 * maximum value in the list OR -1 if the list is empty.
 */
int get_max_value(list *ls) {
  /* get max value by accessing the last element of sortedList */
  if ((ls->size) == 0) // when sortedList is empty
    return -1;
  else // return the last element
    return (ls->sortedList)[(ls->size)-1];
}

/**
 * This function takes a pointer to the list and returns the minimum value in
 * the list OR -1 if the list is empty.
 */
int get_min_value(list *ls) {
  /* get min value by accessing the first element of sortedList */
  if ((ls->size) == 0) // when sortedList is empty
    return -1;
  else // return the first element
    return (ls->sortedList)[0];
}

/**
 * This function returns the index of the first occurrence of 'val' in the
 * list. It returns -1 if the value 'val' is not present in the list.
 */
int search(list *ls, int val) {
  /* check whether the input value is in sortedList */
  int i = 0;

  // find the first occurence of the input value in sortedList
  while ((i < (ls->size)) && (val != (ls->sortedList)[i]))
    i++;

  if (i == (ls->size)) // when the input value is not in sortedList
    return -1;
  else // when the input value is in sortedList
    return i;
}

/**
 * This function returns the minimum value from the list and removes it from the
 * list. It returns -1 if the list is empty.
 */
int pop_min(list *ls) {
  /* find the min value and remove it from sortedList */
  int i = 1, min;

  if ((ls->size) == 0) // when sortedList is empty
    return -1;

  min = (ls->sortedList)[0]; // get the min value

  for (; i < (ls->size); i++) // remove the min value from sortedList
    (ls->sortedList)[i-1] = (ls->sortedList)[i];

  ls->size -= 1; // update size

  return min;
}

/**
 * This function print the contents of the sorted list on a single line as follows:
 * 1 4 6 7 8
 */
void print(list *ls) {
  /* print the whole sortedList using loop */
  int i;

  for (i = 0; i < (ls->size); i++) // print every element in sortedList
    printf("%d ", (ls->sortedList)[i]);

  printf("\n");
}

/**
 * Identical to get_min_value(), but implemented in ARM assembly
 * (use given file get_min_ARM.s)
 */
int get_min_ARM(list *ls);

/**
 * Identical to get_max_value(), but implemented in ARM assembly
 * (use given file get_max_ARM.s)
 */
int get_max_ARM(list *ls);
