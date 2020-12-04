final: final.o
	gcc final.o -o final
	
final.o: final.c
	gcc -c final.c

clean:
	/bin/rm *.o bell.tar.gz
	
run:
	./final
	
	
tarball:
	tar -czvf bell.tar.gz final.c makefile 

