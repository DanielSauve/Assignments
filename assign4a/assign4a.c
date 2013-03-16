#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
int main(void){
	//Test case where the first array is exhauted before the second one
	double one[]={1,3.3,5.6,6};
	double two[]={1.2,3,5,5.2,5.6,7};
	int k;
	int n1=sizeof(one)/sizeof(double), n2=sizeof(two)/sizeof(double);
	sort(one,two,n1,n2,&k);
	double*result=(double*)malloc(sizeof(double)*k);
	result=sort(one,two,n1,n2,&k);
	if (!(result[0]>=0.99&&result[0]<=1.01&&result[1]>=1.19&&result[1]<=1.21&&result[2]>=2.99&&result[2]<=3.01&&result[3]>=3.29&&result[3]<=3.31&&result[4]>=4.99&&result[4]<=5.01&&result[5]>=5.19&&result[5]<=5.21&&result[6]>=5.59&&result[6]<=5.61&&result[7]>=5.99&&result[7]<=6.01&&result[8]>=6.99&&result[8]<=7.01)){
		printf("Expected 1: 1.0 Actual 1: %f Expected 2: 1.2 Actual 2: %f Expected 3: 3.0 Actual 3: %f Expected 4: 3.3 Actual 4: %f Expected 5: 5.0 Actual 5: %f Expected 6: 5.2 Actual 6: %f Expected 7: 5.6 Actual 7: %f Expected 8: 6.0 Actual 8: %f Expected 9: 7.0 Actual 9: %f", result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7], result[8]);
	}
	else printf("Test case one passed\n");
	free(result);
	//Test case where both arrays are exhausted at the same time
	double three[]={1,2,6};
	double four[]={1.2,4,5,6};
	n1=sizeof(three)/sizeof(double);
	n2=sizeof(four)/sizeof(double);
	sort(three,four,n1,n2,&k);
	result=(double*)malloc(sizeof(double)*k);
	result=sort(three,four,n1,n2,&k);
	if(!(result[0]>=0.99&&result[0]<=1.01&&result[1]>=1.19&&result[1]<=1.21&&result[2]>=1.99&&result[2]<=2.01&&result[3]>=3.99&&result[3]<=4.01&&result[4]>=4.99&&result[4]<=5.01&&result[5]>=5.99&&result[5]<=6.01)){
		printf("Expected 1: 1.0 Actual 1: %f Expected 2: 1.2 Actual 2: %f Expected 3: 2.0 Actual 3: %f Expected 4: 4.0 Actual 4: %f Expected 5: 5.0 Actual 5: %f Expected 6: 6.0 Actual 6: %f", result[0], result[1], result[2], result[3], result[4], result[5]);
	}
	else printf("Test case two passed\n");
	free(result);
	//Test case where the second array is exhausted 
	double five[]={8,9};
	double six[]={1,2,3};
	n1=sizeof(five)/sizeof(double);
	n2=sizeof(six)/sizeof(double);
	sort(five,six,n1,n2,&k);
	result=(double*)malloc(sizeof(double)*k);
	result=sort(five,six,n1,n2,&k);
	if(!(result[0]>=0.99&&result[0]<=1.01&&result[1]>=1.99&&result[1]<=2.01&&result[2]>=2.99&&result[2]<=3.01&&result[3]>=7.99&&result[3]<=8.01&&result[4]>=8.99&&result[4]<=9.01)){
		printf("Expected 1: 1.0 Actual 1: %f Expected 2: 2.0 Actual 2: %f Expected 3: 3.0 Actual 3: %f Expected 4: 8.0 Actual 4: %f Expected 5: 9.0 Actual 5: %f", result[0], result[1], result[2], result[3], result[4]);
	}
	else printf("Test case three passed\n");
	free(result);
	return 0;
}
