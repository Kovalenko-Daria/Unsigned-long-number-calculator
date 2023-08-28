unsigned_num_calc: unsigned_num_calc.o calc.o
	gcc -Wall -Werror -Wextra unsigned_num_calc.o calc.o -o unsigned_num_calc

unsigned_num_calc.o: unsigned_num_calc.c
	gcc -Wall -Werror -Wextra -c unsigned_num_calc.c -o unsigned_num_calc.o

calc.o: calc.c
	gcc -Wall -Werror -Wextra -c calc.c -o calc.o

.PHONY:rebuild clean all
 
rebuild:clean all

clean:
	rm -rf *.o unsigned_num_calc

all: unsigned_num_calc