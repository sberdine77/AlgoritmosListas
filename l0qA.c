#include <stdio.h>
#include <stdlib.h>

long int f91(long int N){
	if(N >= 101){
		return N - 10;
	}
	else{
		return f91(f91(N + 11));
	}
}

int main(){
	int n, out;
	
	scanf("%d", &n);
	while(n != 0){
		out = f91(n);
		printf("f91(%d) = %d\n", n, out);
		scanf("%d", &n);
	}
	return 0;
}