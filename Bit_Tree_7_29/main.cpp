#include <iostream>
#include <stdlib.h>
#include <stdio.h>
typedef int datatype;
using namespace std;

typedef struct BitNode
{
    datatype  data;
    struct BitNode *left;
    struct BitNode *right;
}BitNode;

void CreatBitTree(BitNode *tree)
{
   datatype c;
   cin>>c;
   if(c == 9) return;
   if(c == 0) tree = NULL;
   else{
   tree = (BitNode*)malloc(sizeof(BitNode));
   tree->data = c;
   cout<<tree->data;
   CreatBitTree(tree->left);
   CreatBitTree(tree->right);
   }
}
void visit(datatype c,int level)
{
    if(c == 4)
        cout<<"D is in the"<<level<<" Th level"<<endl;
}

void ProTree(BitNode* tree,int level)
{
    if(tree->data != 9)
    {
        visit(tree->data,level);
        ProTree(tree->left,level+1);
        ProTree(tree->right,level+1);
    }
}

int main()
{
    int level=1;
    BitNode* Btree = NULL;
    CreatBitTree(Btree);
    ProTree(Btree,level);
    return 0;
}
