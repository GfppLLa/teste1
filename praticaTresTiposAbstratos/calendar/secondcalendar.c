/*main file*/
#include<stdlib.h>
#include<stdio.h>
#include "calendar_list.h"
/*
here :
        menu
        Calendar:
    manage up to 100 contacts 
                        must add and edit informations like:
                                                            email
                                                            phone
                                                            name
                                                            address
                        operations:
                                    Add contact
                                                the terminal read the informations from the user
                                    show contacts
                                                show all the contacts 
                                    search for contact
                                                        disclaimer: use various methods
                                    remove contact(to be decided)
                                    exit
    structure->
             ->createNode
    main->
*/
/*
menu function must run indefinitely
                                    ->read a number from terminal
                                    ->compare the number to the options
                                    ->if number, call function correspondently
                                            1->add: stack tree
                                            =function read returns the readings
                                                2->show all
                                                    3-> search for a contact; stack tree
                                                    =function to read something
                                                    return to the search function
                                                        4->remove contact
                                                        =function read will return the char to be compared

*/  
#define MAX_SIZE 100
#define MIN_SIZE 1
#define STRUCT_ELEMENTS 4
#include <stdio.h>
#include <stdlib.h>
void clearBuffer()
{
    int charac;
    while((charac=getchar())!='\n'&&charac!=EOF)
    {

    }
}
void removeNewLine(char*plaintext)
{
    //kinda explain itself
    int i=0;
    while (plaintext[i]!='\n')
    {
        if(plaintext[i]=='\n'){plaintext[i]='\0'; break;}
        i++;
    }
}
char*read()
{
 //using the max_size read the keyboard and the return it 
    char *reading;   
    reading=(char*)calloc(MAX_SIZE, sizeof(char));
        if (reading==NULL)
        {
            exit(1);
        }
        while(1)
        {
            //read and only break if greater than min size
            fscanf(stdin, "%[^\n]", reading);
            clearBuffer;
            //the logic to verify the size
            size_t len=strlen(reading);
            if(len>=MIN_SIZE&&len<MAX_SIZE-1)
            {
                //sair
                removeNewLine(reading);
                return reading;
            }
            printf("\n******insert maximum of 100 letters*****");
        }
}
void operationD()//remove contact
{

}
void operationC()//search contact
{

}
void operationB()//show all elements
{

}
void operationA(node**calendarlist)//add element on the list
{
      //create a 2d char array
     //use the read function to fill the collunmns
    //at he end sent it to the insertNode()
    char**content;
    
    for(int i=0; i<STRUCT_ELEMENTS; i++)//run the lines
    {

    }

}
int main(int argc, char*argv[])
{
    node*calendarList;
    while(1)
    {
        printf("\n--menu--\n");
            while(1)
            {
                char operationToken=getche();
                if(operationToken>='1'&&operationToken<='4'){
                    if(operationToken=='1')operationA(&calendarList);
                    if(operationToken=='2')operationB();
                    if(operationToken=='3')operationC();
                    if(operationToken=='4')operationD();
                    break;
                }
                printf("\nbe aware of the options***\n");
            }
             //the outer loop to descide if get in the op menu again
            //must ask if exit ou again
    }
}