#define CALENDAR_LIST_H

typedef struct List node;
node**crateNode(node**head, char*content);//only called bay the insert node
node**insertNode(node**head, char*content);//to insert at end
node**findNode(node** head, char*content, int instructor);//called in finding node and in removing node
node**removeNode(node**head, char*content, int intructor);
void freeNode(node**head);//only receives de node and remove it



