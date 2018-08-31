#include<stdio.h>
#include<stdbool.h>
typedef int Elemtype;

#define MAXSIZE 50

typedef struct{
  Elemtype data[MAXSIZE];
  int length;
}SqList;

void InitList(SqList *L)
{
  L->length = 0;
  printf("length is %d\n",L->length);
}

bool ListInsert(SqList *L,int i,Elemtype e)
{
  if(i < 1 || i > L->length + 1) return false; //the scope of i needs to be suitable.
  if(L->length >= MAXSIZE) return false; //the length can't more than MAXSIZE.
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
  for(int i = 0;i < MAXSIZE;i++)
  {
    L.data[i] = i;
    L.length++;
  }
  if(ListDelete(&L,10,&e)) ListShow(&L);
  printf("The delete data is %d\n",e);
  if(ListInsert(&L,5,155)) ListShow(&L);
  if(e = ListSearch(&L,15)) printf("the first 15 in L is %d",e);
  else printf("can't find 15 in L!");
  return 0;
}
