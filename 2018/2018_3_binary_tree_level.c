# include<stdlib.h>
# include<stdio.h>

typedef struct binaryTree
{
    int data;
    struct binaryTree *lchild;
    struct binaryTree *rchild;
}BiTNode;

int width[100]= {0,};
int depth = 0;

BiTNode* insert(BiTNode *subroot, int d)
{    
    if(subroot == NULL)
    {
        BiTNode *tn = (BiTNode*)malloc(sizeof(BiTNode));
        tn->data = d;
        tn->lchild = NULL;
        tn->rchild = NULL;
        subroot = tn;
    }
    else if(d < subroot->data)
    {
        // printf("%d ",subroot->data);
        subroot->lchild = insert(subroot->lchild, d);
    }
    else
    {
        subroot->rchild = insert(subroot->rchild, d);
    }
    return subroot;
}

void pret(BiTNode *root, int d)
{
    if(root)
    {
        // printf("depth %d ", d);
        width[d] += 1;
        // printf("%d\n",root->data);
        d = d + 1;
        pret(root->lchild, d);
        pret(root->rchild, d);
    }
}

int main()
{
    BiTNode *root = NULL;
    int d = 0;
    while (1)
    {
        scanf("%d", &d);
        if(d == -1)
        {
            break;
        }
        root = insert(root, d);
    }
    pret(root,0);

    int max = 0;
    for(int i = 0; i < 100; i++)
    {
        if(width[i] > max)
            max = width[i];
    }
    printf("%d", max);
    
    return 0;
}

// 1 -1
// 1

// 8 9 7 5 7 -1
// 2

// 8 9 7 5 7 8 9 -1
// 4