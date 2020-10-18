/*************************************************************************
  > File Name: stack.c
  > Author:perrynzhou 
  > Mail:perrynzhou@gmail.com 
  > Created Time: 日 10/18 10:47:54 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../cstl/list.h"
/** 设计一个栈，同时能获取栈中最大元素、最小元素 **/
int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  list *lt = list_create(sizeof(int));
  int max, min;
  for (int i = 0; i < n; i++)
  {
    int *data = (int *)list_push_front(lt);
    *data = rand() % 1024;
    if (i == 0)
    {
      max = min = *data;
    }
    else
    {
      if (*data > max)
      {
        max = *data;
      }
      if (*data < min)
      {
        min = *data;
      }
    }
    fprintf(stdout, "insert value=%d,min=%d,max=%d\n", *data, min, max);
  }
  for (int i = 0; i < n; i++)
  {
    int *data = list_pop_front(lt);
    if (i == 0)
    {
      min = max = *data;
    }
    else
    {
      if (*data > max)
      {
        max = *data;
      }
      if (*data < min)
      {
        min = *data;
      }
    }
    fprintf(stdout, "insert value=%d,min=%d,max=%d\n", *data, min, max);
  }
  list_destroy(lt);
  return 0;
}
