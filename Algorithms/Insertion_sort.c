#include<stdio.h>

int main(void){
    int a[100];
    int i=0;
    int j=0;
    for(i=0;i<100;i++){
        scanf("%d",a[i]);
    }
    for(j=1;j<100;j++){
        int key=a[j];
        i=j-1;
        while(i>=0&&a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }

    for(i=0;i<100;i++){
        printf("%d ",a[i]);
    }
}