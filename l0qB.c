#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

int main(){

	int i, j, k, numberOfCases;
	int firstTerm = 0, secondTerm = 1;

	scanf("%d", &numberOfCases);

	for(i = 1; i <= numberOfCases; i++){
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		int *arr;
		if(((a + b) >= 26) && (((a + b) - a) < 100)){
			arr = (int *) calloc ((((a + b) - a) + 1), sizeof(int));
		}

		printf("Case %d: ", i);
		for(j = 0; j < (a + b); j++){
			int next;
			if(j <= 1){
				next = j;
			}
			else{
				next = ((firstTerm + secondTerm) % 100000);
				firstTerm = secondTerm;
				secondTerm = next;
			}
			if ((j >= (a - 1)) && ((a + b) < 26)){
				printf("%d ", next);
			}
			else if((j >= (a - 1)) && ((a >= 26) || ((a + b) >= 26))){
				if ((j - (a - 1)) < 100){
					arr[(j - (a - 1))] = next;
				}
			}
		}
		if(((a + b) >= 26) && (((a + b) - a) < 100)){
			quick_sort(arr, 0, ((a + b) - a));
			for (k = 0; k <= (((a + b) - a)); k++){
				printf("%d ", arr[k]);
			}
		}
		firstTerm = 0;
		secondTerm = 1;
		printf("\n");
	}

}