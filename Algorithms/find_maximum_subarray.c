#include<stdio.h>
#include<stdlib.h>

int* find_max_crossing_subarray(int* a, int low, int mid, int high){
    int* result;
    int left_sum=-99999;
    int right_sum=-99999;
    int left_max=mid;
    int right_max=mid+1;
    int sum=0;
    int i=0;
    int m=0;
    int n=0;
    
    result=(int*)malloc(3*sizeof(int));
    
    for(i=mid;i>=low;i--){
        sum+=a[i];
        if(sum>left_sum){
            left_sum=sum;
            left_max=i;
            //printf("ls: %d ",left_sum);
            m++;
        }
    }
    

    sum=0;
    for(i=mid+1;i<=high;i++){
        sum+=a[i];
        if(sum>right_sum){
            right_sum=sum;
            right_max=i;
            n++;
            //printf("rs: %d",right_sum);
        }
    }
    result[0]=left_max;
    result[1]=right_max;
    result[2]=left_sum+right_sum;
    //printf("\n%d %d\n",m,n);
    //printf("low: %3d high: %3d mid: %3d \n",low,high,mid);
    //printf("left: %3d right: %3d sum: %3d\n\n",result[0],result[1],result[2]);

    return result;
}

int* find_maximum_subarray(int* a, int low, int high){
    int* result;
    result=(int*)malloc(3*sizeof(int));

    result[0]=low;
    result[1]=high;
    result[2]=a[low];

    if(high==low)
        return result;
    else{
        int mid=(low+high)/2;
        int* left;
        int* right;
        int* cross;

        left=(int*)malloc(3*sizeof(int));
        right=(int*)malloc(3*sizeof(int));
        cross=(int*)malloc(3*sizeof(int));

        left=find_maximum_subarray(a,low,mid);
        //printf("1");
        right=find_maximum_subarray(a,mid+1,high);
        //printf("2");
        cross=find_max_crossing_subarray(a,low,mid,high);
        //printf("3");
        if(left[2]>=right[2]&&left[2]>=cross[2])
            return left;
        else if(right[2]>=left[2]&&right[2]>=cross[2])
            return right;
        else if(cross[2]>=right[2]&&cross[2]>=left[2])
            return cross;
    }
}


int main(void){
    int a[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int low=0;
    int high=15;

    
    int* result;
    
    result=find_maximum_subarray(a,low,high);
    
    printf("left: %d\nright: %d\nsum: %d\n",result[0],result[1],result[2]);

    return 0;



}