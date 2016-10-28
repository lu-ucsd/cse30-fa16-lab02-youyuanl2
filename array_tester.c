/* Name: Youyuan Lu
 * PID:  A92022633
 * 
 * This program is used to test functions in arraysort.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "arraysort.h"

int test_createlist(int max);
int test_insert(list * ls, int value);
int test_remove_val(list * ls, int value);
int test_get_max_value(list * ls);
int test_get_min_value(list * ls);
int test_search(list * ls, int value);
int test_pop_min(list * ls);

int main(void) {

  /* Test Cases for createlist */
  if (!test_createlist(1))
    puts("Failed: test case 1 for createList");
  else if (!test_createlist(8))
    puts("Failed: test case 2 for createList");
  else if (!test_createlist(20))
    puts("Failed: test case 3 for createList");
  else if (!test_createlist(50))
    puts("Failed: test case 4 for createList");
  else if (!test_createlist(80))
    puts("Failed: test case 5 for createList");
  else
    puts("Passed: test cases for createList");

  /* Test Cases for insert */
  list * ls = createlist(2);
  if (!test_insert(ls, 1))
    puts("Failed: Test Case 1 for insert");
  else if (!test_insert(ls, 3))
    puts("Failed: Test Case 2 for insert");
  else if (!test_insert(ls, 5))
    puts("Failed: Test Case 3 for insert");
  else if (!test_insert(ls, 2))
    puts("Failed: Test Case 4 for insert");
  else if (!test_insert(ls, 5))
    puts("Failed: Test Case 5 for insert");
  else
    puts("Passed: Test Cases for insert");

  /* Test Cases for remove_val */
  if (!test_remove_val(ls, 3))
    puts("Failed: Test Case 1 for remove_val");
  else if (!test_remove_val(ls, 5))
    puts("Failed: Test Case 2 for remove_val");
  else if (!test_remove_val(ls, 7))
    puts("Failed: Test Case 3 for remove_val");
  else if (!test_remove_val(ls, 1))
    puts("Failed: Test Case 4 for remove_val");
  else if (!test_remove_val(ls, 2))
    puts("Failed: Test Case 5 for remove_val");
  else
    puts("Passed: Test Cases for remove_val");

  /* Test Cases for get_max_value */
  if (!test_get_max_value(ls))
    puts("Failed: Test Case 1 for get_max_value");
  else {
    insert(ls, 1);
    if (!test_get_max_value(ls))
      puts("Failed: Test Case 2 for get_max_value");
    else {
      insert(ls, 3);
      if (!test_get_max_value(ls))
        puts("Failed: Test Case 3 for get_max_value");
      else {
        insert(ls, 5);
        if (!test_get_max_value(ls))
          puts("Failed: Test Case 4 for get_max_value");
        else {
          insert(ls, 2);
          if (!test_get_max_value(ls))
            puts("Failed: Test Case 5 for get_max_value");
          else
            puts("Passed: Test Cases for get_max_value");
        }
      }
    }
  }

  /* Test Cases for get_min_value */
  if (!test_get_min_value(ls))
    puts("Failed: Test Case 1 for get_min_value");
  else {
    remove_val(ls, 1);
    if (!test_get_min_value(ls))
      puts("Failed: Test Case 2 for get_min_value");
    else {
      remove_val(ls, 3);
      if (!test_get_min_value(ls))
        puts("Failed: Test Case 3 for get_min_value");
      else {
        remove_val(ls, 5);
        if (!test_get_min_value(ls))
          puts("Failed: Test Case 4 for get_min_value");
        else {
          remove_val(ls, 2);
          if (!test_get_min_value(ls))
            puts("Failed: Test Case 5 for get_min_value");
          else
            puts("Passed: Test Cases for get_min_value");
        }
      }
    }
  }

  /* Test Cases for search */
  if (!test_search(ls, 8))
    puts("Failed: Test Case 1 for search");
  else {
    insert(ls, 1);
    if (!test_search(ls, 1))
      puts("Failed: Test Case 2 for search");
    else {
      insert(ls, 3);
      if (!test_search(ls, 2))
        puts("Failed: Test Case 3 for search");
      else {
        insert(ls, 5);
        if (!test_search(ls, 3))
          puts("Failed: Test Case 4 for search");
        else {
          insert(ls, 5);
          if (!test_search(ls, 5))
            puts("Failed: Test Case 5 for search");
          else
            puts("Passed: Test Cases for search");
        }
      }
    }
  }

  /* Test Cases for pop_min */
  if (!test_pop_min(ls))
    puts("Failed: Test Case 1 for pop_min");
  else if (!test_pop_min(ls))
    puts("Failed: Test Case 2 for pop_min");
  else if (!test_pop_min(ls))
    puts("Failed: Test Case 3 for pop_min");
  else if (!test_pop_min(ls))
    puts("Failed: Test Case 4 for pop_min");
  else if (!test_pop_min(ls))
    puts("Failed: Test Case 5 for pop_min");
  else
    puts("Passed: Test Cases for get_min_value");

  free(ls->sortedList);
  free(ls);
  return 0;
}

/* tester for createlist */
int test_createlist(int max) {
  list * ls;
  int passed;

  ls = createlist(max); // try to malloc a new list
  if (ls == NULL) // malloc unsuccessful
    return 1;
  else if ((ls->sortedList) && // createlist functions properly
      (ls->size) == 0 && (ls->maxSize) == max)
    passed = 1;
  else // createlist doesn't function properly
    passed = 0;

  free(ls->sortedList);
  free(ls);
  return passed;
}

/* tester for insert */
int test_insert(list * ls, int value) {
  int size = ls->size, i, j, temp;
  int arr[size+1];

  for (i = 0; i < size; i++)
    arr[i] = (ls->sortedList)[i];

  i = insert(ls, value);
  if (i == -1) // insert unsuccessful
    return 1;
  else if ((ls->sortedList)[i] != value) // incorrect return value
    return 0;
  else if ((size + 1) != (ls->size)) // doesn't update size
    return 0;

  arr[size] = value;

  for (i = 1; i < (size + 1); i++) // bubble sort arr
    for (j = 0; j < (size + 1) - i; j++)
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }

  for (i = 0; i < (size + 1); i++) // compare arr with ls->sortedList
    if (arr[i] != (ls->sortedList)[i])
      return 0;

  return 1;
}

/* tester for reimove_val */
int test_remove_val(list * ls, int value) {
  int size = ls->size, count, i;

  for (count = i = 0; i < size; i++) // account the number of value
    if ((ls->sortedList)[i] == value)
      count++;

  if (count != remove_val(ls, value)) // incorrect return value
    return 0;
  else if ((ls->size) != size - count) // doesn't update size
    return 0;

  for (i = 0; i < (ls->size); i++) // if all occurence of value are removed
    if ((ls->sortedList)[i] == value)
      return 0;

  for (i = 0; i < (ls->size); i++) // if ls->sortedList is still sorted
    if ((ls->sortedList)[i] > (ls->sortedList)[i+1])
      return 0;

  return 1;
}

/* tester for get_max_value */
int test_get_max_value(list * ls) {
  int return_val = get_max_value(ls), max, i;

  if ((ls->size) == 0) // when ls->sortedList is empty
    if (return_val == -1) // correct return value
      return 1;
    else // incorrect return value
      return 0;

  // get the min of ls->sortedList
  for (max = (ls->sortedList)[0], i = 1; i < (ls->size); i++)
    if (max < (ls->sortedList)[i])
      max = (ls->sortedList)[i];

  if (max != return_val) // incorrect return value
    return 0;

  return 1;
}

/* tester for get_min_value */
int test_get_min_value(list * ls) {
  int return_val = get_min_value(ls), min, i;

  if ((ls->size) == 0) // when ls->sortedList is empty
    if (return_val == -1) // correct return value
      return 1;
    else // incorrect return value
      return 0;

  // get the max of ls->sortedList
  for (min = (ls->sortedList)[0], i = 1; i < (ls->size); i++)
    if (min > (ls->sortedList)[i])
      min = (ls->sortedList)[i];

  if (min != return_val) // incorrect return value
    return 0;

  return 1;
}

/* tester for search */
int test_search(list * ls, int value) {
  int i;

  for (i = 0; i < (ls->size); i++) // if value is in ls->sortedList
    if (value == (ls->sortedList)[i])
      break;

  if (i == (ls->size)) // when value is not in ls->sortedList
    i = -1;

  if (i != search(ls, value)) // incorrect return value
    return 0;

  return 1;
}

/* tester for pop_min */
int test_pop_min(list * ls) {
  int size = (ls->size);
  int arr[size];
  int return_val, min, i;

  for (i = 0; i < size; i++)
    arr[i] = (ls->sortedList)[i];

  return_val = pop_min(ls);

  if (size == 0) // when ls->sortedList is empty
    if (return_val == -1) // correct return value
      return 1;
    else // incorrect return value
      return 0;
  else if ((ls->size) != (size - 1)) // doesn't update size
    return 0;

  for (min = arr[0], i = 1; i < size; i++) // get the min of ls->sortedList
    if (min > arr[i])
      min = arr[i];

  if (min != return_val) // incorrect return value
    return 0;

  for (i = 1; i < size; i++) // if the min has been removed
    if (arr[i] != (ls->sortedList)[i-1])
      return 0;

  return 1;
}
