SRC=src/*.cpp src/utils/*.cpp
BIN=out/lukas
INCLUDE= -I src/include
LINKER= -L src/lib
LD_FLAGS= -lmingw32 -lSDL2main -lSDL2

default: ${SRC}
	g++ ${INCLUDE} ${LINKER} -o ${BIN} ${SRC} ${LD_FLAGS}
	clear

run:
	cd out
	.\lukas.exe
	cd ../