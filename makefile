BINDIR = ./bin

output: main.c
	gcc $< -o ${BINDIR}/$@

.PHONY: clean

clean:
	@rm ${BINDIR}/*