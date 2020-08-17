#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int Elemtype;

#define INITSIZE  50  //initial size
#define INCRESIZE 10  //increase size every time

typedef struct{
  Elemtype *data;
  int MAXSize,length;
}SqList;

void InitList(SqList *L)
{
  L->length = 0;
  L->data = (Elemtype *)malloc(sizeof(Elemtype)*INITSIZE);
  L->MAXSize = INITSIZE;
  printf("length is %d\n",L->length);
}

bool ListRealloc(SqList *L)
{
  L->data = (Elemtype *)realloc(L->data,sizeof(Elemtype)*(L->MAXSize + INCRESIZE));
  if(L->data == NULL) return false;
  L->MAXSize += INCRESIZE;
  return true;
}

bool ListInsert(SqList *L,int i,Elemtype e)
{
  if(i < 1 || i > L->length + 1) return false; //the scope of i needs to be suitable.
  if(L->length >= L->MAXSize)
  {
    if(!ListRealloc(L)) return false;
  }
  for(int j = L->length;j >= i;j--)
  {
    L->data[j] = L->data[j-1];
  }
  L->data[i-1] = e;
  L->length++;
  return true;
}

bool ListDelete(SqList *L,int i,Elemtype *e)
{
  if(i < 1 || i > L->length) return false; //the scope of i needs to be suitable.
  *e = L->data[i-1];
  for(int j = i;j < L->length;j++)
  {
    L->data[j-1] = L->data[j];
  }
  L->length--;
  return true;
}
//search the item appears in L for the first time.
int ListSearch(SqList *L,Elemtype e) 
{
  for(int i = 0;i < L->length;i++)
  {
    if(L->data[i] == e) return (i+1);
  }
  return false;
}
void ListShow(SqList *L)
{
  for(int i = 0;i < L->length;i++)
  {
    printf("L->data[%d] = %d\n",i,L->data[i]);
  }
}

int main(int argc,int *argv[])
{
  SqList L;
  int e;
  InitList(&L);
  for(int i= 0;i < L.MAXSize;i++)
  { 
    L.data[i] = (Elemtype)i;
    L.length++;
  }
  ListShow(&L);
  if(ListInsert(&L,5,155)) ListShow(&L);
  if(ListDelete(&L,10,&e)) ListShow(&L);
  printf("The delete data is %d\n",e);
  if(e = ListSearch(&L,15)) printf("the first 15 in L is %d\n",e);
  else printf("can't find 15 in L!\n");
  return 0;
}
