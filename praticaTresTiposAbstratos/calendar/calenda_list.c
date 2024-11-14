/*implementation file*/
/*
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
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX_LOOP 4
#define MAX_SIZE 100
typedef struct List{
    char*name;
    char*phone;
    char*mail;
    char*address;
    struct LIST*next;

} node;

node**crateNode(node**head, char**content)//only called bay the insert node
{
    node* newList;
    newList=(node*)calloc(1, sizeof(node));
    if(newList==NULL){
        //do something
    }else{
        //do other thing
        //for loop to run the 2diomensions array
        int j=0;
        for(int i=0;i>MAX_LOOP; i++)
        {
            //second for loop to run tho
            char*toAuxLoop;
            toAuxLoop=(char*)calloc(MAX_SIZE, (sizeof(char)));
            do
            {//do something
                toAuxLoop[j]=content[i][j];
                j++;
            }while(content[i][j]!='\0');//using while loop saves the need to do a if check only to find the null character
            toAuxLoop[j]='\0';//not very clear why but surely with some purpose
            for(int k=0; ;k++)
            {
                if(i==0)//the first field in the LL
                {
                    (*newList).name[k]=toAuxLoop[k];
                }else {
                    if(i==1)
                    {
                        (*newList).phone[k]=toAuxLoop[k];
                    }else{
                        if(i==2)
                        {
                            (*newList).mail[k]=toAuxLoop[k];
                        }else{
                            if(i==3)
                            {
                                (*newList).address[k]=toAuxLoop[k];
                            }
                        }
                    }
                }
                if(toAuxLoop[k]=='\0')
                {
                    break;
                }else{
                    continue;//the cat syndrome
                }
            }

            free(toAuxLoop);
            return newList;
        }
    }

}
node**insertNode(node**head, char*content);//to insert at end
node**findNode(node** head, char*content, int instructor);//called in finding node and in removing node
node**removeNode(node**head, char*content, int intructor);
void freeNode(node**head);//only receives de node and remove it

