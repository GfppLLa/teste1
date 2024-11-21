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
#define MAX_LOOP 4
#define MAX_SIZE 100
typedef struct List{
    char*name;
    char*phone;
    char*mail;
    char*address;
    struct LIST*next;

} node;
/**
 * 
 * createNode - put the content in the list array
 * 
 * description:
 * 
 * 
 * 
 * parameters:
 * @head: a pointer to pointer of the addres of the head element of the list
 * 
 * @content: a pointer to pointer of an 2d array containing the data
 * 
 * return:
 * the addres of the new node already alloced and the data insert
 */
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
            
        }
    }
     //todo: remove from here the insertion of the content in the list node
    //maybe not
 //todo: remember to change te function to void
//todo again: change the passing of addres to the insert function, 
return head;
}
/**
 * 
 * insertNode - put the node in the arraylist
 * 
 * description:
 * 
 * 
 * 
 * parameters:
 * @head: a pointer to pointer of the addres of the head element of the list
 * 
 * @content: a pointer to pointer of an 2d array containing the data
 * 
 * return:
 * the head adddres already changed
 */
node**insertNode(node**head, char**content)//to insert at end
{
    //todo: transfer to here the insertion of the content in the list node
   //not todo: the previously one
  //19/11: not used, by now
  node *newList=crateNode(&head, &content);
  if(newList!=NULL)
  {
    (*newList).next=*head;
    *head=newList;
  }
return newList;
}
/**
 * 
 * findNode - return or not the address to a certain string diven
 * description:
 * ind and return the address of the node using the element given as key, the **content houses the 
 * element in the index mathing its type, the int instructor denote the type 
 * 
 * 
 * parameters:
 * @
 * 
 * @
 * 
 * return: the address
 * 
 */
node**findNode(node** head, char**content, int instructor)//called in finding node != and in removing node
{
    node* runAux=head;
    char ;
    while((*runAux).next !=NULL)
    {
        switch (instructor)
        {
        case 1://nome
            if( strcmp((*runAux).name,content[instructor])==0)
            {
                return runAux;
            }else{
                runAux=(*runAux).next;
            }  
            break;
        case 2://phone
            if( strcmp((*runAux).phone,content[instructor])==0)
            {
                return runAux;
            }else{
                runAux=(*runAux).next;
            }  
            break;
        case 3://mail
            if( strcmp((*runAux).mail,content[instructor])==0)
            {
                return runAux;
            }else{
                runAux=(*runAux).next;
            }  
            break;
        case 4://address
            if( strcmp((*runAux).address,content[instructor])==0)
            {
                return runAux;
            }else{
                runAux=(*runAux).next;
            }  
            break;
        }
    }
    return NULL;
}
/**
 * 
 * removeNode - remove a node from the list
 * 
 * description: receives a adddres and removes its from the memory
 * 
 * 
 * 
 * parameters:
 * @head: address of the fisrt element
 * 
 * return:
 * 
 */
removeNode(node**head, node*targetNode)
{
    node *auxOnde;
    //first verify if the target node is the first
    if (*head == targetNode)
    {
        node* tempOne=*head;
        *head= (*head)->next;//not sure why use two dereferenciation
        free(tempOne);
        return;
    }
    //to do if the target node is not the first
    node*currentNode=*head;
    while((*currentNode).next != NULL && (*currentNode).next!= targetNode)
    {
        currentNode=(*currentNode).next;//exit when find the node we're looking for or reach the last list
    }

    if((*currentNode).next==(*targetNode).next)
    {
        (*currentNode).next=(*targetNode).next;//the current node receives the node that the target pointed
        free(targetNode);                     //and remove the target
    }

}
/**
 * 
 * findNode - 
 * 
 * description:
 * 
 * 
 * 
 * parameters:
 * @
 * 
 * @
 * 
 * return:
 * 
 */
void freeNode(node**head);//only receives de node and remove it

