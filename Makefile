all:
	cc -o ascii -g main.c ascii_art.c fonts.c

clean:
	rm -f ascii

