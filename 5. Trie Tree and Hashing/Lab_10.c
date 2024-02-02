// Display the words in a trie data structure in lexicographic order. 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Trie
{
    // char info;
    struct Trie *child[26];
    int isLeaf;
}TRIE;

void insert(TRIE* root, char *pattern);
void display(TRIE* root, char *str, int level);
void displayTree(TRIE* root, char *str, int level, int length);

int search(TRIE* root,char *str);

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

    printf("Enter the word that you to search in the trie tree:\n");
    scanf("%s", str);
    if(!search(root,str))
    {
        printf("The word %s not found in the trie tree\n", str);
    }
    else
    {
        printf("The word %s found in the trie tree\n", str);
    }
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

int search(TRIE* root,char *str)
{
    TRIE *cur = root;
    int l = strlen(str);

    for(int i = 0; i < l; i++)
    {
        int index = str[i] - 'a';
        if(cur->child[index] == NULL)
        {
            return 0;
        }
        cur = cur->child[index];
    }
    return 1;
}

// search for particular word
// deleting 


