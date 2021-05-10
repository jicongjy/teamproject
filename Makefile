travel : travel.c travel.o
	gcc -c travel travel_main.c travel.o
product.o : travel.c travel.h
	gcc -c travel.c -o travel.o
clean :
	rm *o travel
