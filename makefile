all: vetor.l vetor.y
	flex -i vetor.l
	bison vetor.y
	gcc vetor.tab.c -o vetor -lm
	./vetor


	