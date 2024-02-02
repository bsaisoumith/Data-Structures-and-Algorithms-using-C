#include<stdio.h>
#include<stdlib.h>

typedef struct Trie
{
    // char info;
    struct Trie *child[26];
    int isLeaf;
}TRIE;

void insert(TRIE* root, char *pattern);
void display(TRIE* root, char *str, int level);
void displayTree(TRIE* root, char *str, int level, int length);
int search(TRIE* root, char *pattern, int level);
TRIE* delete(TRIE* root, char *pattern, int length, int level);

TRIE* createNode()
{
    TRIE *temp = (TRIE*)malloc(sizeof(TRIE));
    temp->isLeaf = 0;
    for(int i = 0; i < 26; i++)
    {
        temp->child[i] = NULL;
    }
    return temp;
}

int main()
{
    TRIE *root = createNode();
    char str[100];
    int length;
    insert(root,"ant");
    insert(root,"apple");
    insert(root,"anticipate");
    insert(root,"that");
    insert(root,"this");
    insert(root,"designer");
    printf("Data in the trie tree is as shown below\n");
    display(root,str,0);
    printf("Enter the length of data in the trie tree you want:\n");
    scanf("%d",&length);
    displayTree(root,str,0,length);

    if(search(root,"ant",0))
    {
        printf("ant is found\n");
    }
    else
    {
        printf("ant is not found\n");
    }

    if(search(root,"anticipate",0))
    {
        printf("an is found\n");
    }
    else
    {
        printf("an is not found\n");
    }

    delete(root,"ant",3,0);

    return 0;
}

void insert(TRIE* root, char *pattern)
{
    //printf("%c", *pattern);
    TRIE *cur = root;
    while(*pattern)
    {
        if(cur->child[*pattern - 'a'] == NULL)
        {
            cur->child[*pattern - 'a'] = createNode();
        }
        cur = cur->child[*pattern - 'a'];
        pattern++;
    }
    cur->isLeaf = 1;
}

void display(TRIE* root, char *str, int level)
{
    if(root->isLeaf)
    {
        str[level] = '\0';
        printf("%s\n",str);
    }
    for(int i = 0; i < 26; i++)
    {
        if(root->child[i] != NULL) 
        {
            str[level] = i + 'a';
            display(root->child[i],str,level+1);
        }
    }
}

void displayTree(TRIE* root, char *str, int level, int length)
{
    if(root->isLeaf && length == level)
    {
        str[level] = '\0';
        printf("%s\n",str);
    }
    for(int i = 0; i < 26; i++)
    {
        if(root->child[i] != NULL)
        {
            str[level] = i + 'a';
            displayTree(root->child[i],str,level+1,length);
        }
    }
}

int search(TRIE* root, char *pattern, int level)
{
    TRIE* cur = root;
    while(*pattern)
    {
        if(cur->child[*pattern - 'a'] == NULL)
        {
            return 0;
        }
        cur = cur->child[*pattern - 'a'];
        pattern++;
    }
    // if(*pattern == NULL)
    // return 1;
    if(cur->isLeaf == 1)
    {
        return 1;
    }
    return 0;
}

TRIE* delete(TRIE* root, char *pattern, int length, int level)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(length == level)
    {
        if(root->isLeaf)
        {
            root->isLeaf = 0;
        }
        if(isEmpty(root))
        {
            free(root);
            return NULL;
        }  
    }
    delete(root,pattern,length,level+1);
}

int isEmpty(TRIE* root)
{
    for(int i = 0; i < 26; i++)
    {
        if(root->child[i] != NULL)
        {
            return 0;
        }
    }
    return 1;
}

void delete_trie(struct trienode *root, char *key)
{
    int i,index,k;
    struct trienode *curr;
    struct stack x;
    curr=root;
    for(i=0;key[i]!='\0';i++)
    {
        index=key[i];
        if(curr->child[index]==NULL)
        {   
            printf("The word not found..\n");
            return;
        }
        push(curr,index);
        curr=curr->child[index];
    }
    curr->endofword=0;
    push(curr,-1);
    while(1)
    {
        x=pop();
        if(x.index!=-1)
            x.m->child[x.index]=NULL;
        if(x.m==root)//if root
            break;
        k=check(x.m);
        if((k>=1)||(x.m->endofword==1))
            break;
        else
            free(x.m);
    }
    return;
}

// search for particular word
// deleting 