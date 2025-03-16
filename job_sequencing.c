#include <stdio.h>
#include <stdbool.h>

void sort(int ids[], int profits[], int deadlines[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profits[j] < profits[j + 1]) {
                int tempProfit = profits[j];
                profits[j] = profits[j + 1];
                profits[j + 1] = tempProfit;

                int tempDeadline = deadlines[j];
                deadlines[j] = deadlines[j + 1];
                deadlines[j + 1] = tempDeadline;

                int tempID = ids[j];
                ids[j] = ids[j + 1];
                ids[j + 1] = tempID;
            }
        }
    }
}

void jobSequencing(int ids[] , int profit[] , int deadline[] , int n){
    sort(ids , profit , deadline , n);

    int maxDeadline = 0;
    for(int i = 0 ; i < n ; i++){
        if (maxDeadline < deadline[i] ) maxDeadline = deadline[i];
    }

    int slots[maxDeadline] ;
    bool isSlotsFilled[maxDeadline];

    for(int i = 0 ; i < maxDeadline ; i++){
        slots[i] = -1 ;
        isSlotsFilled[i] = false;
    }

    int res = 0;

    for(int i = 0 ; i < n ; i++ ){
        for(int j = deadline[i] - 1 ; j >= 0 ;j--){
            if(!isSlotsFilled[j]){
                slots[j] = ids[i];
                isSlotsFilled[j] = true;
                res += profit[i];
                break; 
            }
        }
    }
    printf("\nresult : %d", res);
}

int main() {
    int n = 5;
    int ids[] = {1, 2, 3, 4, 5};          // Job IDs
    int profits[] = {100, 19, 27, 25, 15}; // Profits
    int deadlines[] = {2, 1, 2, 1, 3};     // Deadlines

    jobSequencing(ids, profits, deadlines, n);

    return 0;
}