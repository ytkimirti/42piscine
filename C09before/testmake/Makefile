# -*- MakeFile -*-

all: geom tip

geom: geom.o gd.o
	clang geom.o gd.o -o geom -lm

geom.o: geom.c
	clang -c geom.c

gd.o: gd.c
	clang -c gd.c

tip: tip.o gd.o
	clang tip.o gd.o -o tip

tip.o: tip.c
	clang -c tip.c

