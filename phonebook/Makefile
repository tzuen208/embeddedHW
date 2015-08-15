compile: phonebook.c phonebook_v2.c
	gcc -O0 -o phonebook phonebook.c
	gcc -O0 -o phonebook_v2 phonebook_v2.c

run: phonebook phonebook_v2 clearcache
	perf stat -e cache-misses ./phonebook
	perf stat -e cache-misses ./phonebook_v2
time: phonebook phonebook_v2
	./phonebook
	./phonebook_v2

clearcache: clearcache.c
	gcc -o clearcache clearcache.c

C: clearcache
	./clearcache
