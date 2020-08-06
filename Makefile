

main: main.o rem.o filesystem.o int_list.o options.o re.o
	gcc -g main.o rem.o filesystem.o int_list.o options.o re.o -o main

main.o: src/main.c
	gcc	-c src/main.c

rem.o: src/rem.c src/rem.h src/options.h src/int_list.h
	gcc	-c src/rem.c

filesystem.o: src/filesystem.c src/filesystem.h src/rem.h src/options.h src/int_list.h
	gcc	-c src/filesystem.c

options.o: src/options.c src/options.h
	gcc	-c src/options.c

int_list.o: src/int_list.c src/int_list.h
	gcc	-c src/int_list.c

re.o: tiny-regex-c/re.c tiny-regex-c/re.h
	gcc -c tiny-regex-c/re.c

clean:
	rm *.o
