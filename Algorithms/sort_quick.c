#include<stdio.h>
#include<stdlib.h>

int partition(int* a, int p, int r){
    int x=a[r-1];
    int i=p;

    int j=0;
    for(j=p;j<r;j++){
        if(a[j]<=x){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
        }
    }
    return i;

}

void quicksort(int*a, int p, int r){
    if(p<r){
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q,r);
    }
}


int randomized_partition(int* a,int p,int r){
    int i=rand()%(r-p);

    int temp=a[p+i];
    a[p+i]=a[r-1];
    a[r-1]=temp;
    return partition(a,p,r);
}

void randomized_quicksort(int* a, int p, int r){
    if(p<r){
        int q=randomized_partition(a,p,r);
        randomized_quicksort(a,p,q-1);
        randomized_quicksort(a,q,r);
    }
}


int hoare_partition(int* a, int p, int r){
    int x=a[p];
    int i=p-1;
    int j=r;
    while(1){
        do{
            j--;
            //printf("1");
        }
        while(a[j]>x);
        do{
            i++;
           // printf("2");
        }
        while(a[i]<x);

        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            int k=0;
        }
        else return j;
    }
}



int partition_same(int* a, int p, int r){
    r--;
    int x=a[r];
    int i=p-1;
    int k=0;
    int t=r;
    for(int j=p;j<r-1;j++){
        if(a[j]==x){
            if(a[j]!=a[r-1]){
                int temp=a[j];
                a[j]=a[r-1];
                a[r-1]=temp;
                r--;
            }
            else{
                j--;
                r--;
            }
        }
    }
    for(int l=0;l<16;l++)
        printf("%d ",a[l]);
    printf("\n");
    printf("r=%d\n",r);

    for(int j=p;j<r;j++){
        if(a[j]<=x){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            for(int l=0;l<16;l++)
                printf("%d ",a[l]);
            printf("\n");
            printf("j=%d i=%d\n",j,i);
        }
    }

    for(int h=0;h<t-r+1;h++){
        int temp=a[i+h+1];
        a[i+h+1]=a[r+h];
        a[r+h]=temp;
        for(int l=0;l<16;l++)
            printf("%d ",a[l]);
        printf("\n");
        printf("i+h+1=%d r+h=%d\n",i+h+1,r+h);
    }
    printf("q=%d t=%d\n",i+1,t-r+i+1);
    return i+1;

}


int main(void){
    int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int low=0;
    int high=15;
    int b[12]={13,19,9,5,12,8,7,4,11,2,6,21};
    int c[16]={1,5,8,2,9,5,5,7,6,16,10,15,12,6,-1,5};



    partition_same(c,0,16);


    /*
    //int w=randomized_partition(a,0,16);
    int i=0;
    for(i=0;i<16;i++) printf("%d ",a[i]);
    printf("\n");
    hoare_partition(b,0,12);

    randomized_quicksort(a,0,16);


    //printf("\n%d ",w);
    for(i=0;i<16;i++) printf("%d ",a[i]);
*/
    return 0;



}




