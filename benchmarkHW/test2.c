int findGCD(int a, int b) {

        while (1) {

            a %= b;

            if (a == 0) return b;

            if (a == 1) return 1;

            b %= a;

            if (b == 0) return a;

            if (b == 1) return 1;

        }

    }
int main(void){
	int i, j;

	for(i =2; i<10000;i++){
		for(j = i;j<10000;j++){
			if(i^j)
				findGCD(i,j);
		}
	}
	return 0;
}
