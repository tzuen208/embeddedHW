int findGCD(int a, int b) {

        while (1) {

            if (a > (b * 4)) {

                a %= b;

                if (a == 0) return b;

                if (a == 1) return 1;

            } else if (a >= b) {

                a -= b;

                if (a == 0) return b;

                if (a == 1) return 1;

            }

            if (b > (a * 4)) {

                b %= a;

                if (b == 0) return a;

                if (b == 1) return 1;

            } else if (b >= a) {

                b -= a;

                if (b == 0) return a;

                if (b == 1) return 1;

            }

        }

    }
int main(void){
	int i, j;

	for(i = 2; i <10000;i++){
		for(j=i; j<10000; j++){
				findGCD(i,j);
		}
	}
	return 0;
}
