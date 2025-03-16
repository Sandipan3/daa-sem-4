#include <stdio.h>

int max(int a , int b){
    return (a > b) ? a : b;
}

int knapsack(int w, int wt[] , int val[], int n){

    if(!w || !n)    return 0;

    if(wt[n-1] > w)     return knapsack(w, wt, val , n-1);

    return max(knapsack(w , wt, val , n-1) , val[n-1] + knapsack(w-wt[n-1], wt, val , n-1));
}

int main(){

    int values[] = { 3, 4, 5, 6 };
    int weight[] = { 2, 3, 4, 5 };
    int W = 8;
    int n = sizeof(values) / sizeof(values[0]);

    printf(
        "Maximum value that can be put in knapsack: %d\n",
        knapsack(W, weight, values, n));

    return 0;
}
