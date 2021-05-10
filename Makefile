travel : travel.c travel.o
	gcc -o travel travel_main.c travel.o
travel.o : travel.c travel.h
	gcc -c travel.c -o travel.o
clean :
	rm *o travel
