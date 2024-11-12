/*
programam with 3 user interactions 
    1.add and interval of numbers
        1.1 use queue or linked list
    2.verify some number in any of the intervals added
    3.exit
  instructions:
    if user insert 1:
        read 2 numbers, 
        the bigger be the 2 on the linked list
    if user want to check
        read a number
        run the linked list and verify if the number is in some interval
        if yes: put interval, order of the linked list and number
    if user exit
        free memory and exit  
Structure:
    structure-> 
              ->creatoNo
              ->insertInBegin
              ->insertInEnd
              ->removeNo
              ->findNo
              ->showList
              ->freeList
*/
#include<stdlib.h>
#include<stdio.h>
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
node* findNode(node**head, int toTest)
{
//receive a number, compare it in each list element
    node* runAux=*head;
    while((*runAux).next!=NULL)
    {
        if(toTest<=(*runAux).end &&toTest >= (*runAux).start)
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


/*
    
    main->operation->readOption
                    ->read interval
                    ->read Find
                    ->showList[removido]
                    ->exit
*/

void menuLoop(int *returnSelectedOpt)
{
    system("clear");
    char reading;
    print("\n1 to inser interval\n2 to verify interval\n3 to exit\n");
    reading=_getch();
    if(reading >='1'&&reading<='3')
    {
        *returnSelectedOpt=reading;
        return ;
    }else{
        print("\n***accepted inputs 1 to 3***\n");
        getch();
        menuLoop(returnSelectedOpt);
    }
}
void getNumberInterval(node**listOne)
{
    system("clear");
    printf("\ninsert the first number of the interval:");
    int numberOne=0;
        while (1)
        {
            char temp;
            temp=_getch();
            if(temp>'1'&&temp<='100')
            {
                numberOne=temp-'0';
                break;
            }else{
                printf("\n>number between 1 and 100<");
                _getch();
                system("clear");
            }
        }
    printf("\ninsert the second number of the interval:");
    int numberTwo=0;
        while(1){
            char temp;
            temp=_getch();
            if(temp>'1'&&temp<='100'){
                numberTwo=temp-'0';
            }else{
                printf("\n>number between 1 and 100<");
                _getch();
                system("clear");
            }
        }
        if(numberOne>numberTwo)
        {
            int aux=numberOne;
            numberOne=numberTwo;
            numberTwo=aux;
        }else{
            if(numberOne==numberTwo)
            {
                printf("\n>numbers cannot be equal<");
                _getch();
                getNumberInterval(listOne);
            }
        }
        insertInBegin(listOne, numberOne, numberTwo);
}
void operation()
{   
    int *returnSelectedOpt;
    node* listOne;
    returnSelectedOpt=(int*)calloc(1, sizeof(int));
    switch (*returnSelectedOpt)
    {
    case '1':
        getNumberInterval(&listOne);
        break;
    
    default:
        break;
    }

}
int main(int argc, char*argv[])
{
    

return 0;
}