#include<stdio.h>

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



int main(void){
    int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int low=0;
    int high=15;

    
    int w=partition(a,0,16);
    int i=0;
    for(i=0;i<16;i++) printf("%d ",a[i]);
    quicksort(a,0,16);


    printf("\n%d ",w);
    printf("\n");
    for(i=0;i<16;i++) printf("%d ",a[i]);
    //int* result;
    
    //result=find_maximum_subarray(a,low,high);
    
    //printf("left: %d\nright: %d\nsum: %d\n",result[0],result[1],result[2]);

    return 0;



}