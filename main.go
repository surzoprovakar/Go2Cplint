package main

/*
#include <stdlib.h>
#cgo CFLAGS: -g -Wall
#cgo LDFLAGS: -L. -L/usr/lib/swi-prolog/lib/x86_64-linux/ -lcaller -lswipl

float callGregory(const char* predName);
*/
import "C"
import (
	"fmt"
	"unsafe"
)

func main() {
	/*
		cfloat := C.GoString(C.callGregory(C.CString("pheads")))
		if s, err := strconv.ParseFloat(cfloat, 32); err == nil {
			fmt.Println("probability is ", s)
		}
		cfloat = C.GoString(C.callGregory(C.CString("ptails")))
		if s, err := strconv.ParseFloat(cfloat, 32); err == nil {
			fmt.Println("probability is ", s)
		}
	*/
	cfloat := C.callGregory(C.CString("pheads"))
	//r := make([]float32, 1)
	//copy(r, (*[1 << 20]float32)(unsafe.Pointer(&cfloat))[:])
	//C.free(unsafe.Pointer(cfloat))
	r := (*[1 << 20]float32)(unsafe.Pointer(&cfloat))[:]
	fmt.Println("Probability is ", r[0])
}
