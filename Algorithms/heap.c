void max_heapify(int* a, int n, int i){
    int l=2*i;
    int r=i*2+1;
    int largest=0;

    if(l<n&&a[l]>a[i])
        largest=l;
    else largest=i;

    if(r<n&&a[r]>a[largest])
        largest=r;
    if(largest!=i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=a[i];
        max_heapify(a,n,largest);
    }
}

void build_max_heap(int* a, int n){
    int i=0;
    for(i=n/2-1;i>=0;i--)
        max_heapify(a,n,i);
}

void heap_sort(int* a, int n){
    build_max_heap(a,n);
    int i=0;
    for(i=n-1;i>0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        n--;
        max_heapify(a,n,0);
    }
}

void heap_insert(int* a, int n, int key){
    a[n-1]=key;
    n++;
    build_max_heap(a,n);
}

int heap_maximum(int* a){
    return a[0];
}

int heap_extract_max(int* a, int n){
    if(n<1)
        printf("Error: Heap underflow\n");
        return 0;
    
    int max=a[0];
    a[0]=a[n-1];
    n--;
    max_heapify(a,n,0);
    return max;
}

void heap_increase_key(int* a, int i, int key){
    if(key<a[i]){
        printf("Error: New key is smaller than current key.\n");
        return;
    }
    a[i]=key;
    while(i>0&&a[i/2]<a[i]){
        int temp=a[i];
        a[i]=a[i/2];
        a[i/2]=temp;
        i/=2;
    }
}

