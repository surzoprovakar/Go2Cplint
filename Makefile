MAKEFLAGS += --silent
INCLUDES = -I  /usr/lib/swi-prolog/include/
LI = -L=-L/usr/lib/swi-prolog/lib -L/usr/lib/swi-prolog/lib/x86_64-linux
DL = -Wl,-rpath-link,/usr/lib/swi-prolog/lib/x86_64-linux/
PRELOAD=/usr/lib/libswipl.so:/usr/lib/x86_64-linux-gnu/libtinfo.so.6.2
all: Caller

Caller: Caller.cpp
	g++ -Wno-unused-result $(INCLUDES) $(LI) $(DL) -o Caller Caller.cpp -lrt -lpthread -lswipl
	go build *.go
run:
	LD_PRELOAD=$(PRELOAD) ./Caller ./main

clean:
	rm Caller 