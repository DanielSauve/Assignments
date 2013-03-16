double* sort(double* one, double* two, int n1, int n2, int *fatty)
{
	double result[n1+n2];
	int i=0,j=0,k=0;
	while (i<n1&&j<n2){
		if (one[i]<two[j]){
			result[k]=one[i];
			i++;
			k++;
		}
		else if (one[i]>two[j]){
			result[k]=two[j];
			j++;
			k++;
		}
		else{
			result[k]=one[i];
			i++;
			j++;
			k++;
		}
	}
	while (i<n1){
		result[k]=one[i];
		i++;
		k++;
	}
	while (j<n2){
		result[k]=two[j];
		j++;
		k++;
	}
	*fatty=k+1;
	double res2[k+1];
	i=0;
	while (i<k){
		res2[i]=result[i];
		i++;
	}
	return res2;
}
