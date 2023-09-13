GCC=gcc
AS=as
LD=ld
LFLAG=-g

SRC := $(wildcard *.s)
EXE := $(SRC:.s=.out)
all: $(EXE)

%.out:
	$(AS) $(@:.out=.s) $(LFLAG) -o $(@:.out=.o)
	$(LD) $(@:.out=.o) $(LFLAG) -o $(@:.out=)

clean: 
	rm -f *.o

purge: clean 
	rm -f  $(EXE:.out=)