all: delete main clean

binario:
	gcc -W -Wall geracaoBinario.c -o geracaoBinario
	clear

clean:
	clear

delete: 
	@rm -rf src/*.o

main: nre.c
	gcc -W -Wall nre.c -o nre