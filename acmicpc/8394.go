package main

import (
	"bufio"
	"fmt"
	"os"
)

var bufin = bufio.NewReader(os.Stdin)
var bufout = bufio.NewWriter(os.Stdin)

func main() {
	var n, a, b, c int
	b = 1
	defer bufout.Flush()
	fmt.Fscan(bufin, &n)

	for i:=1; i<=n; i++ {
		c = (a + b) % 10
		a = b
		b = c
	}
	
	fmt.Println(b)
}
