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



int main(void){
    int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int low=0;
    int high=15;

    
    //int w=randomized_partition(a,0,16);
    int i=0;
    for(i=0;i<16;i++) printf("%d ",a[i]);
    printf("\n");
    randomized_quicksort(a,0,16);


    //printf("\n%d ",w);
    for(i=0;i<16;i++) printf("%d ",a[i]);

    return 0;



}