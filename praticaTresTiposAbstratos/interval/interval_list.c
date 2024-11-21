#include <stdlib.h>
#include <stdio.h>
#include "interval_list.h"

typedef struct List
{
    int start;
    int end;
    struct List* next;
}node;
node* createNode(int start, int end)//using the create node to make the allocation centralized
{
    node* newList;
    newList=(node*)calloc(1, sizeof(node));//using calloc to not need to atribute NULL
    if (newList!=NULL)//if the allocation did work
        {
            (*newList).start=start;
            (*newList).end=end;
        }
    return newList;
}
void insertInBegin(node**head, int start, int end)
{
    node* newNode=createNode(start, end);
    if(newNode!=NULL)
    {
        (*newNode).next=*head;//the "next" field in the new list receive the address to the head element
        *head=newNode;//and the addres to head recive the address to the new
    }
}
void insertInEnd(node**head, int start, int end)
{
    node* newNode=createNode(start, end);
    if(newNode==NULL)return;
    if(*head==NULL)
    {
        *head=newNode;//if head node is empty the new assumes as the first
    }
    node* atNow=*head;//a temporary node receivess the head address
        while((*atNow).next != NULL)//run the list til the last node
        {
            atNow=(*atNow).next;//the code to run the list, atNow address receives the next address pointed
        }
        (*atNow).next=newNode;//in the end the address pointed at the last node receives the newNode location
}
node* findNode(node**head, int *toTest)
{
//receive a number, compare it in each list element
    node* runAux=*head;
    while((*runAux).next!=NULL)
    {
        if(*toTest<=(*runAux).end &&*toTest >= (*runAux).start)
        {   
            return runAux;
        }else{
            runAux=(*runAux).next;
        }
    }
    return NULL; 
}
void freeNodes(node**head)
{
    node *auxOne=*head;
    while((*auxOne).next!= NULL)
    {
        if((*auxOne).next==NULL)
        {
            free(auxOne);
        }else{
        node* proto = auxOne;
        auxOne=(*auxOne).next;
        free(proto);
            }
    }
}