GCC=gcc
AS=as
LD=ld
LFLAG=-g

all: fibonacci counter return


fibonacci: 
	$(AS) fibonacci.s $(LFLAG) -o fibonacci.o
	$(LD) fibonacci.o $(LFLAG) -o fibonacci

counter: 
	$(AS) counter.s $(LFLAG) -o counter.o
	$(LD) counter.o $(LFLAG) -o counter

return: 
	$(AS) return.s $(LFLAG) -o return.o
	$(LD) return.o $(LFLAG) -o return


clean: 
	rm -f *.o

purge: clean 
	rm -f fibonacci counter return pilha