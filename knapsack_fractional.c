#include <stdio.h>


void sort(int wt[] , int val[] , int n){
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - 1 - i ; j++ ){
            double r1 = (val[j]*1.0 / wt[j]);
            double r2 = (val[j+1]*1.0 / wt[j+1]);
            if(r1 < r2){
                int t1 = val[j];
                val[j] = val[j+1];
                val[j+1] = t1;

                int t2 = wt[j];
                wt[j] = wt[j+1];
                wt[j+1] = t2;
            }
        }
    }
}

void fractionalKnapsack(int wt[], int val[], int n, int w){
    sort(wt , val , n);

    double res = 0.0;

    for(int i = 0 ; i < n ; i++){
        if(w == 0) break;

        if(wt[i] <= w){
            res += val[i];
            w-= wt[i];
        }else{
            res += (val[i] *1.0 * w)/wt[i];
            w = 0;
        }
    }
    printf("\nresult : %.2f", res);
}

int main() {
    int n = 5;
    int wt[] = {2, 3, 4, 5, 9}; 
    int val[] = {3, 4, 5, 8, 10}; 
    int w = 10; 

    printf("Number of items: %d\n", n);
    printf("Weights of items: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", wt[i]);
    }
    printf("\nValues of items: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", val[i]);
    }
    printf("\nCapacity of the knapsack: %d\n", w);

    fractionalKnapsack(wt, val, n, w);

    return 0;
}
