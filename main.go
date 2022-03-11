package main

/*
#cgo CFLAGS: -g -Wall
#cgo LDFLAGS: -L. -L/usr/lib/swi-prolog/lib/x86_64-linux/ -lcaller -lswipl

const char* callGregory(const char* predName);
*/
import "C"
import (
	"fmt"
	"strconv"
)

func main() {
	cfloat := C.GoString(C.callGregory(C.CString("pheads")))
	if s, err := strconv.ParseFloat(cfloat, 32); err == nil {
		fmt.Println("probability is ", s)
	}
	cfloat = C.GoString(C.callGregory(C.CString("ptails")))
	if s, err := strconv.ParseFloat(cfloat, 32); err == nil {
		fmt.Println("probability is ", s)
	}
}
