rm alfa.c
cp a.c alfa.c
make
echo ".................Compilando"
./alfa

echo ".................Compilando asm"
nasm -g -o yyin.o -f elf32 yyin.nasm
gcc -m32 -o  yyin yyin.o lib/alfalib.o
./yyin
