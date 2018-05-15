#include<stdio.h>

void marge_without_twist(int a[], int p, int q, int r){
    int n1=q-p+1;    //size of left subset
    int n2=r-q;      //size of right subset
    int left[1000]={0};  //decalare the left subset
    int right[1000]={0}; //decalare the right subset
    int i=0;  //temp number
    int l_count=0; //counter that counts how many elements in the left subset has been marged
    int r_count=0; //counter that counts how many elements in the right subset has been marged
    for(i=0;i<n1;i++)
        left[i]=a[p+i];  //initiallize the left subset
    for(i=0;i<n2;i++)
        right[i]=a[q+i]; //initiallize the right subset
    for(i=0;i<r-q+1;i++){
        if(l_count>=n1&&r_count<n2){
            a[i]=right[r_count];
            r_count++; //if all the elements in the left subset have been used, add the left elements in the right subset to the result

        }
        else if(r_count>=n2&&l_count<n1){
            a[i]=left[l_count];
            l_count++; //if all the elements in the right subset have been used, add the left elements in the left subset to the result
        }
        else if(l_count<n1&&r_count<n2){
            if(right[r_count]>left[l_count]){
                a[i]=left[l_count];
                l_count++;
            }
            else if(left[l_count]>right[r_count]){
                a[i]=right[r_count];
                r_count++;
            }
            else if(left[l_count]=right[r_count]){
                a[i]=left[l_count];
                l_count++;
                r_count++;
            }
        }
    }
    return;
}

void marge_with_twist(int a[], int p, int q, int r, int twist){
    int n1=q-p+1;
    int n2=r-q;
    int left[1000]={0};
    int right[1000]={0};
    int i=0;
    int l_count=0;
    int r_count=0;

    for(i=0;i<n1;i++)
        left[i]=a[p+i];
    left[i]=twist;
    for(i=0;i<n2;i++)
        right[i]=a[q+i];
    right[i]=twist;

    for(i=0;i<r-q+1;i++){
        if(right[r_count]>left[l_count]){
            a[i]=left[l_count];
            l_count++;
        }
        else if(left[l_count]>right[r_count]){
            a[i]=right[r_count];
            r_count++;
        }
        else if(left[l_count]=right[r_count]){
            a[i]=left[l_count];
            l_count++;
            r_count++;
        }
    }
    return;
}

void marge_sort_with_twist(int a[], int p, int r, int twist){
    int q=0;
    if(p<r){
        q=(q+r-1)/2;
        marge_sort_with_twist(a,p,q,twist);
        marge_sort_with_twist(a,q+1,r,twist);
        marge_with_twist(a,p,q,r,twist);
    }
}

void marge_sort_without_twist(int a[], int p, int r){
    int q=0;
    if(p<r){
        q=(q+r-1)/2;
        marge_sort_without_twist(a,p,q);
        marge_sort_without_twist(a,q+1,r);
        marge_without_twist(a,p,q,r);
    }
}

//test
int main(void){
    int a[1000];
    int b[1000];
    int i=0;
    int j=0;
    int n=0;
    scanf("%d",&n);
    for(i=0;i<100;i++){
        scanf("%d",a[i]);
        b[i]=a[i];
    }
    marge_sort_with_twist(a,0,n-1,10000);
    marge_sort_without_twist(b,0,n-1);

    for(i=0;i<100;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=0;i<100;i++){
        printf("%d ",b[i]);
    }

    
}

/*

0 1 2 v 3 4 5
1 2 4 v 5 6 7

p=0; q=2; r=5;

*/