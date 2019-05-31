#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct node{
    struct node * parent;
    int lenSum;
    int depth;
}node,* pnode;

int findDepth(char * input, int index){
    int depth = 0;
    for(int i = index + 1;;i++){
        if(input[i] == '\t'){
            depth++;
        }else{
            break;
        }
    }
    return depth;
}

int lengthLongestPath(char * input){
    int lonLen = 0;
    pnode parent = (pnode)malloc(sizeof(node));
    parent->parent = NULL;
    parent->lenSum = 0;
    parent->depth = -1;
    int tempLen = 0;
    int isFile = 0;
    for(int i = 0; i <= strlen(input); i++){
        if(input[i] != '\n' && input[i] != '\0'){
            if(input[i] == '.') isFile = 1;
            tempLen++;
        }else{
            pnode tempNode = (pnode)malloc(sizeof(node));
            tempNode->parent = parent;
            tempNode->lenSum = parent->lenSum + tempLen + 1;
            tempNode->depth = parent->depth + 1;
            if((tempNode->lenSum >= lonLen) && isFile == 1){
                lonLen = tempNode->lenSum;
            }
            isFile = 0;
            tempLen = 0;
            
            int nextDepth = 0;
            if(i != strlen(input)){
                nextDepth = findDepth(input, i);
                i += nextDepth;
                if(nextDepth > tempNode->depth){
                    parent = tempNode;
                }else if(nextDepth < tempNode->depth){
                    for(int j = 0; j < tempNode->depth - nextDepth; j++){
                        pnode temp = parent;
                        parent = parent->parent;
                        free(temp);
                    }
                }
            } 
            else if(lonLen != 0){
                lonLen -= 1;
            }
        }
    }
    return lonLen;
}

int main(void){
    char a[] = "a\n\taa\n\t\taaa\n\t\t\tfile1234567890123.txt\naaaaaaaaaaaaaaaaaaaaa\n\tsth.png";
    printf("%d\n", strlen(a));
    printf("%d", lengthLongestPath(a));
    return 0;
}