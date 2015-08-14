int findGCD(int a, int b){
	while (1) {
		if(a>b) a-=b;
		else if (a<b) b-=a;
		else return a;
	}	
}

int main(void){

	int i, j;

	for(i = 2; i <10000; i++){
		for(j = i ; j<10000; j++){
			if(i ^ j)
				findGCD(i,j);
		}
	}
	return 0;
}
