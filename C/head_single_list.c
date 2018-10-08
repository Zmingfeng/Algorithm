#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;

typedef struct LNode{
  ElemType data;      //data field
  struct LNode *next; //pointer filed
}LNode, *LinkList;

//from head node insert new node
LinkList CreatListFromHead(LinkList L)
{
  LNode *S;
  int x;
  L = (LNode *)malloc(sizeof(LNode));
  L->next = NULL;
  scanf("Please input data for list:%d",&x);
  while(x != EOF)  //press ctrl+D to end your input. 
  {
    S = (LNode *)malloc(sizeof(LNode));
    S->data = x;
    S->next = L->next;
    L->next = S;
    scanf("Please continue to input data for list:%d",&x);
  }
  return L;
}

//from tail node insert new node
LinkList CreatListFromHead(LinkList L)
{
  int x;
  L = (LNode *)malloc(sizeof(LNode));
  LNode *S,*R = L;
  scanf("Please input data for list:%d",&x);
  while(x != EOF)  //press ctrl+D to end your input. 
  {
    S = (LNode *)malloc(sizeof(LNode));
    S->data = x;
    R->next = S;
    R = S;
    scanf("Please continue to input data for list:%d",&x);
  }
  R->next = NULL;
  return L;
}

//get locate through serial number
LNode *GetElem(LinkList L,int i)
{
  int j = 1;
  LNode *p = L->next; //cause i use the head node,so i need get the first node first.
  if(i == 0) return L; 
  if(i < 0) return NULL;
  while(p && j < i)
  {
    p = p->next;
    j++;
  }
  return p;
}

//get locate through value in the node
LNode *LocateElem(LinkList L,ElemType e)
{
  LNode *p = L->next; //cause i use the head node,so i need get the first node first.
  while(p && p->data != e) p = p->next;
  return p;
}

unsigned int GetLength(LinkList L)
{
  unsigned int length = 0;
  LNode *p = L;
  while(p->next)
  {
    p = p->next;
    length++;
  }
  return length;
}
//insert a node rear the locate node
bool InsertNodeFromRear(LinkList L,int i,ElemType e)
{
  LNode *p;
  if(p = GetElem(L,i-1))
  {
    printf("the locate node beyond the list.");
    return false;
  }
  LNode *S = (LNode *)malloc(sizeof(LNode));
  S->data = e;
  S->next = p->next;
  p->next = S;
  return true;
}
//insert a node before the locate node
bool InsertNodeFromBefore(LinkList L,int i,ElemType e)
{
  LNode *R,*p;
  if(p = GetElem(L,i)) 
  {
    printf("the locate node beyond the list.");
    return false;
  }
  LNode *S = (LNode *)malloc(sizeof(LNode));
  S->data = p->data;
  p->data = e;
  S->next = p->next;
  p->next = S;
  return true;
} 
//delete a node rear the locate node
bool DeleteNodeFromRear(LinkList L,int i,ElemType *e)
{
  LNode *p,*q;
  if(p == GetElem(L,i-1)) 
  {
    printf("the locate node beyond the list.");
    return false;
  }
  if(q = p-next)
  {
    *e = q->data;
    p->next = q->next;
    return true;
    free(q);
    return true;
  }
  else
  {
    printf("the locate node beyond the list.");
    return false;
  }
}
//delete a node before the locate node
bool DeleteNodeFromBefore(LinkList L,int i,ElemType *e)
{
  LNode *R,*p;
  if(p == GetElem(L,i))
  {
    printf("the locate node beyond the list.");
    return false;
  }
  if(R = p-next)
  {
    *e = p->data;
    p->data = R->data;
    p->next = R->next;
    free(R);
    return true;
  }
  else
  {
    printf("the locate node is the last one.please use DeleteNodeFromRear(...).");
    return false;
  }
  return true;
}

int main(int argc,int *argv[])
{
   
  return 0;
}
