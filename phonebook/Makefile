compile: phonebook.c
	gcc -O0 -o phonebook phonebook.c

run: phonebook
	perf stat -e cache-misses ./phonebook

clearcache: clearcache.c
	gcc -o clearcache clearcache.c

C: clearcache
	./clearcache
