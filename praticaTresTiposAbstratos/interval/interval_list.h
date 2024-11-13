//#ifdef INTERVAL_LIST_H
#define iNTERVAL_LIST_H

typedef struct List node;
node* createNode(int start, int end);
void insertInBegin(node**head, int start, int end);
void insertInEnd(node**head, int start, int end);
node* findNode(node**head, int *toTest);
void freeNodes(node**head);

//#endif