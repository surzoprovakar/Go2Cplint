MAKEFLAGS += --silent
LI = -L=-L/usr/lib/swi-prolog/lib -L/usr/lib/swi-prolog/lib/x86_64-linux
DL = -Wl,-rpath-link,/usr/lib/swi-prolog/lib/x86_64-linux/
INCLUDES = -I  /usr/lib/swi-prolog/include/ -I /usr/lib/jvm/default-java/include -I /usr/lib/jvm/default-java/include/linux
PRELOAD=/usr/lib/swi-prolog/lib/x86_64-linux/libswipl.so:/usr/lib/x86_64-linux-gnu/libtinfo.so.6.2

all: Caller

Caller: Caller.cpp
	g++ -Wno-unused-result $(INCLUDES) -shared -fPIC -o libcaller.so Caller.cpp	
	#g++ -Wno-unused-result $(INCLUDES) $(LI) $(DL) -o Caller Caller.cpp -lrt -lpthread -lswipl
	go build *.go
run:
	LD_PRELOAD=$(PRELOAD) LD_LIBRARY_PATH=./ ./main 

clean:
	rm Caller 
