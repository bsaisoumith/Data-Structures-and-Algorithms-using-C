// implementation of dictionary using trie data structure

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Trie
{
    struct Trie *child[26];
    int isLeaf;
    char *synonym;
}TRIE;

TRIE* createNode();
void insert(TRIE* root, char *pattern,char *meaning);
int search(TRIE* root, char *str, char *meaning);

int main()
{
    TRIE *root = createNode();
    insert(root,"accurate","prescise");
    insert(root,"prescise","accurate");

    char meaning[1000];
    if(search(root,"accurate",meaning))
    {
        printf("accurate word is present and it's meaning is %s\n",meaning);
    }
    else
    {
        printf("accurate not found\n");
    }

    if(search(root,"prescise",meaning))
    {
        printf("prescise word is present and it's meaning is %s\n",meaning);
    }
    else
    {
        printf("prescise not found\n");
    }

    if(search(root,"acc",meaning))
    {
        printf("acc word is present and it's meaning is %s\n",meaning);
    }
    else
    {
        printf("acc not found\n");
    }

    return 0;
}

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

void insert(TRIE* root, char *pattern, char *meaning)
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
    cur->synonym = malloc(sizeof(char)*(strlen(meaning)+1));  // size of char * length of meaning + 1 (8)
    strcpy(cur->synonym,meaning);
}

int search(TRIE* root, char *str, char *meaning)
{
    // isEmpty and isLeaf = add few more conditions to avoid code crash
    TRIE* current = root;
    while(*str)
    {
        if(current->child[*str - 'a'] == NULL)
        {
            return 0;
        }
        current = current->child[*str - 'a'];
        *str++;
    }
    strcpy(meaning, current->synonym);
    return 1;
}
