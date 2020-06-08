CC = gcc -ansi -pedantic -lm
CFLAGS = -Wall -std=c99
EXE = sintactico morfologico alfa
PRUEBA = pruebaSintactico prueba_tabla pruebaMorfo
BISON = bison
FLEX = flex

all: $(EXE)
prueba: $(PRUEBA)
.PHONY : clean

generacion.o: generacion.c generacion.h common.h
	@echo "#---------------------------"
	@echo "# Generando $@ "
	$(CC) $(CFLAGS) -c $< -o $@

tablaHash.o: tablaHash.c tablaHash.h common.h
	@echo "#---------------------------"
	@echo "# Generando $@ "
	$(CC) $(CFLAGS) -c $< -o $@

tablaSimbolos.o: tablaSimbolos.c tablaSimbolos.h common.h
		@echo "#---------------------------"
		@echo "# Generando $@ "
		$(CC) $(CFLAGS) -c $< -o $@

alfa.yy.o: alfa.yy.c common.h
	@echo "#---------------------------"
	@echo "# Generando $@ "
	$(CC) $(CFLAGS) -c $< -o $@

alfa.tab.o: alfa.tab.c common.h
	@echo "#---------------------------"
	@echo "# Generando $@ "
	$(CC) $(CFLAGS) -c $< -o $@

alfa.o: alfa.c alfa.h common.h
	@echo "#---------------------------"
	@echo "# Generando $@ "
	$(CC) $(CFLAGS) -c $< -o $@

##########pruebaSintactico
pruebaSintactico: pruebaSintactico.o alfa.yy.o alfa.tab.o
	@echo "#---------------------------"
	@echo "Generando ejecutable de la unidad de prueba para analizador sintactico..."
	$(CC) $(CFLAGS) -o pruebaSintactico $^

pruebaSintactico.o: alfa.tab.o
	@echo "#---------------------------"
	@echo "Compilando unidad de prueba para analizador sintactico..."
	$(CC) $(CFLAGS) -c pruebaSintactico.c alfa.tab.o

##########Prueba tabla
prueba_tabla.o: prueba_tabla.c tablaSimbolos.h tablaHash.h
	@echo "#---------------------------"
	@echo "# Generando $@ "
	$(CC) $(CFLAGS) -c $< -o $@
prueba_tabla: prueba_tabla.o tablaHash.o tablaSimbolos.o
	$(CC) $(CFLAGS) $^ -o $@
###################

pruebaMorfo.o:
	$(CC) $(CFLAGS) -c pruebaMorfo.c
pruebaMorfo: pruebaMorfo.o alfa.yy.c
	$(CC) $(CFLAGS) -o pruebaMorfo pruebaMorfo.o alfa.yy.c

sintactico:
	@echo "#---------------------------"
	@echo "Generando analizador sintactico..."
	$(BISON) -d -y -v -g -o alfa.tab.c alfa.y
	
morfologico: alfa.l alfa.tab.c
	@echo "#---------------------------"
	@echo "Generando analizador morfologico..."
	$(FLEX) -o alfa.yy.c alfa.l

alfa: alfa.o generacion.o tablaHash.o tablaSimbolos.o alfa.yy.o alfa.tab.o
	@echo "#---------------------------"
	@echo "# Generando compilador $@ "
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -f *.o *.yy.c *.tab.c *.tab.h *~ core $(EXE) $(PRUEBA) *.output *.dot
