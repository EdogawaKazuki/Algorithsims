void max_heapify(int* a, int n, int i){
    int l=2*i;
    int r=i*2+1;
    int largest=0;

    if(l<=n&&a[l]>a[i])
        largest=l;
    else largest=i;

    if(r<=n&&a[r]>a[largest])
        largest=r;
    if(largest!=i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=a[i];
        max_heapify(a,n,largest);
    }
}