Compilateur = gcc
Executable = prog
Sources = $(wildcard *.c)
Objets = $(Sources:.c=.o)

all : $(Executable)

%.o : %.c
	$(Compilateur) -o $@ -c $< -g

$(Executable) : $(Objets)
	$(Compilateur) -o $@ $^

clean :
	rm -rf *.o
	
mrproper : clean
	rm -rf prog