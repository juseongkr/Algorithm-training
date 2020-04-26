package main

import (
	"bufio"
	"fmt"
	"os"
)

var bufin = bufio.NewReader(os.Stdin)
var bufout = bufio.NewWriter(os.Stdin)

func xor(n int) int {
	var ret int
	for i:=n/4*4; i<=n; i++ {
		ret ^= i
	}

	return ret
}

func main() {
	var t, s, f int
	defer bufout.Flush()
	fmt.Fscan(bufin, &t);

	for i:=0; i<t; i++ {
		fmt.Fscan(bufin, &s, &f)
		fmt.Println(xor(s-1) ^ xor(f))
	}
}
