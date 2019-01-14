TARGET: exe
libtree.a: tree.o 
	ar rs libtree.a tree.o 
tree.o: tree.c
	gcc -g -c -I . tree.c -o tree.o
diff.o: diff.c
	gcc -g -c -I . diff.c -o diff.o
exe: evaluation.o diff.o libtree.a
	gcc -g evaluation.o diff.o -o exe -L . -ltree
evaluation.o: evaluation.c
	gcc -g -c -I . evaluation.c -o evaluation.o
clean:
	rm *.o
	rm libtree.a
	rm exe
