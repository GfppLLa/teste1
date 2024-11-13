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
#include <stdlib.h>
#include <stdio.h>
#include "interval_list.h"


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
void setNumberInterval(node**listOne)
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
node* getFindNode(node**head)
{
    int *numberToFind;
    numberToFind=(int*)calloc(1, sizeof(int));
    while(1){
        system("clear");
        printf("\ninsert number to be found: ");
        scanf("%d",numberToFind);
        if(*numberToFind>=1 &&*numberToFind<=100)
        {
            printf("****remember to put only 1 to 100*****");
            getch();
            break;
        }
    }
    return (findNode(&head, numberToFind));
}
void operation(int toVerify)
{   
    int *returnSelectedOpt;
    node* listOne;
    returnSelectedOpt=(int*)calloc(1, sizeof(int));
    while(1){//while loop runs 
        menuLoop(returnSelectedOpt);
        switch (*returnSelectedOpt)
        {
        case '1':
            setNumberInterval(&listOne);
            break;
        case '2':
            getFindNode(&listOne);//function to get the number e run it through all the lists
            break;
        case '3':
            freeNodes(&listOne);
            return;
            break;
        }
    }
}
int main(int argc, char*argv[])
{
    operation;

return 0;
}