#include <stdio.h>

//재귀함수를 이용한 fibo
int fibonacci(int n) { // n : 4
	if (n <= 1) 
		return n;
	return fibonacci(n - 2) + fibonacci(n - 1);
}

//반복문을 이용한 fibo
// 0 1 1 2 3 5 8 13 21 34
int fibo(int n){
	int fn_2=0, fn_1=1, fn;	//fn-2 =0, fn-1 =1, fn 이렇게 선언

	if (n==0) return 0;
	else if (n==1) return 1;
	else{
		for (int index=2; index<=n; index++){
			fn= fn_2 + fn_1;
			fn_2=fn_1;
			fn_1=fn;
		}
	}
	return fn;
}


void main() {
	int i;
	for (i = 0; i <= 10; ++i) 
		printf("%d ",fibo(i));	//i번째 피보나치 수열을 출력한다.
}


//4 2 0 (0리턴) 1 (1리턴) (0+1=1리턴) 3 1 (1리턴) 2 0 1 (1리턴) (1+1=2리턴) (1+2=3 리턴) => 3이 결과값

// 재귀호출을 구현하면 꼬리에 꼬리를 물어 너무많은 계산을 하게된다. 이럴땐 일반 for 문을 사용하는게 이득이다.

