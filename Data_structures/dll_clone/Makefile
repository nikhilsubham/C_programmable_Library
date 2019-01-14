TARGET: exe
libdll.a: dll.o 
	ar rs libdll.a dll.o 
dll.o: dll.c
	gcc -g -c -I . dll.c -o dll.o
diff.o: diff.c
	gcc -g -c -I . diff.c -o diff.o
exe: evaluation.o diff.o libdll.a
	gcc -g evaluation.o diff.o -o exe -L . -ldll
evaluation.o: evaluation.c
	gcc -g -c -I . evaluation.c -o evaluation.o
clean:
	rm *.o
	rm libdll.a
	rm exe
