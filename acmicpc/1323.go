package main

import (
	"bufio"
	"fmt"
	"os"
)

var bufin = bufio.NewReader(os.Stdin)
var bufout = bufio.NewWriter(os.Stdin)
var n, k int

func main() {
	defer bufout.Flush()
	fmt.Fscan(bufin, &n, &k);

	l := 1
	for {
		if l > n {
			break
		}
		l *= 10
	}

	m := n % k
	for i:=1; i<=k; i++ {
		if m == 0 {
			fmt.Println(i)
			os.Exit(0)
		}
		m = (m * l + n) % k
	}
	fmt.Println(-1)
}
