#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 2진수로 변환 용도
int returnArray2bin(int num_1[], int num1result) {
	for (int i = 0; i < 8; i++) {
		int res = num1result % 2;
		num1result = num1result / 2;
		num_1[i] = res;
	}
}

// 10진수로 변환 용도
int returnArray2Dec(int num_1[]) {
	int sum = 0; 
	for (int i = 7; i >= 0; i--) {
		if (num_1[i] == 1) {
			sum += pow(2, i);
		} 
	} 
	return sum;
}

// 전가산기 구현 로직
int fullAdder(int num_1[], int num_2[], int num_result[]) {
	int c = 0;
	for (int i = 0; i < 8; i++) {
		int a = num_1[i];
		int b = num_2[i];

		int s = (a ^ b) ^ c;
		c = (a & b) | ((a ^ b) & c);
		num_result[i] = s;
	}
}

// 전가산기, 10진수/2진수 변환 로직을 호출하는 용도
int returnMinusNumberBin(int a, int b) {
	int num_1[8] = { 0 };
	int num_2[8] = { 0 }; 
	int forMinusBinNum[8] = { 1,0,0,0,0,0,0,0 };
	int forMinusBinNumResult[8] = { 0 };
	int forReturnOutputResult[8] = { 0 };
	returnArray2bin(num_1, a);
	returnArray2bin(num_2, b);
	
	for (int i = 7;i >= 0; i--) {
		num_2[i] = !num_2[i]; 
	} 
	fullAdder(num_2, forMinusBinNum, forMinusBinNumResult); 
	fullAdder(num_1, forMinusBinNumResult, forReturnOutputResult);
	 
	 
	int finalResult = returnArray2Dec(forReturnOutputResult);
	printf("Output : %d", finalResult);
}

// 부호 처리가 가능한 함수.. 간단하게 하려면 이렇게 구현하는게 맞네요.
int returnMinusNumberBin2(int num1,int num2) {
	int result = 0;
	result = num1 + (~num2 + 1); 
	return result;
}

// 메인 함수
int pracFunc2(void) {
	int num1, num2;
	scanf_s("%d %d", &num1, &num2); 
	returnMinusNumberBin(num1, num2); 
	return 0;
}

int main(void)
{ 
	pracFunc2(); 
	return 0;
}
