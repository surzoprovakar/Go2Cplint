//
// main.go
// Copyright (C) 2019 Tim Hughes
//
// Distributed under terms of the MIT license.
//
package main

/*
#cgo CFLAGS: -g -Wall
#include "Caller.h"

*/
import "C"
import (
	"fmt"
)

func probQuery() string {
	return "prob(heads(coin),P)."
}
func main() {
	prob := C.GoString(C.call(C.CString(probQuery())))
	fmt.Println("probability is ", prob)
}
