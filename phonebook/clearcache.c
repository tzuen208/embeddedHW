int main() {
	int i ,j;
     const int size = 1024*1024; // Allocate 1M. Set much larger then L2
     char *c = (char *)malloc(size);
     for ( i = 0; i < 0xffff; i++)
       for ( j = 0; j < size; j++)
         c[j] = i*j;
 }
