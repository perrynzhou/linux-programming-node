/*************************************************************************
  > File Name: queue.c
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 日 10/18 11:08:34 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../cstl/list.h"
int main(void)
{
  list *first = list_create(sizeof(int));
  list *second = list_create(sizeof(int));

  for (int i = 0; i < 5; i++)
  {
    int *data = list_push_back(first);
    *data = rand() % 1024;
    fprintf(stdout, "index=%d,value=%d\n", i, *data);
  }
  for (int i = 0; i < 5; i++)
  {
    int *data = list_pop_back(first);
    int *value = list_push_back(second);
    *value = *data;
  }
  for (int i = 0; i < 5; i++)
  {
    int *data = list_pop_front(second);
    fprintf(stdout, "index=%d,value=%d\n", i, *data);
  }
  list_destroy(first);
  list_destroy(second);
  return 0;
}
