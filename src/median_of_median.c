#include <stdio.h>

// 素数
#define N 2999

int A[N];


// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int quick_select(int A[], int n, int k){
    int i, j, pivot;
    if(n<=5){
        pivot = A[0];
        for(i = j = 1; i < n; i++){
            if(A[i] <= pivot){
                swap(A+i, A+j);
                j++;
            }
        }
        if(j == k+1) return pivot;
        else if(j < k+1) return quick_select(A+j, n-j, k-j);
        else return quick_select(A+1, j-1, k);
    }
    else{
        int B[(N+4)/5];
        int h,g,f;
        for(h = 0; h < n/5; h++){
            B[h]=quick_select(A+5*h, 5, 2);
        }
        if(n%5 != 0){
            B[n/5]=quick_select(A+5*(n/5), n%5, (n%5)/2);
        }
        pivot = quick_select(B, (n+4)/5, (n+4)/10);
        for(g=0;g<n;g++){
            if(A[g]==pivot){
                f=g;
                g=n-1;
            }
         }
        A[f] = A[0];
        A[0] = pivot;
        for(i = j = 1; i < n; i++){
            if(A[i] <= pivot){
                swap(A+i, A+j);
                j++;
            }
        }
        if(j == k+1) return pivot;
        else if(j < k+1) return quick_select(A+j, n-j, k-j);
        else return quick_select(A+1, j-1, k);
    }
}

int main(){
    int i;
    A[0] = 0;
    A[1] = 17; //原始元
    for(i=2;i<N;i++){
        A[i] = (long long int) A[i-1] * A[1] % N;
    }
    for(i=0;i<N;i++){
       if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
       //printf("%d th element is %d\n", i, quick_select(A, N, i));//
    }
}
