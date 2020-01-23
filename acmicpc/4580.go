package main

import (
	"bufio"
	"fmt"
	"os"
)

var bufin = bufio.NewReader(os.Stdin)
var bufout = bufio.NewWriter(os.Stdin)

func main() {
	defer bufout.Flush()
	
	for {
		var num [27]int
		var ans [27]int
		var n int
		fmt.Fscan(bufin, &n)

		if n == 0 {
			break
		}

		for i:=1; i<=n; i++ {
			fmt.Fscan(bufin, &num[i])
		}

		var idx int = 0
		for i:=1; i<=n; i++ {
			for {
				if idx == num[i] {
					break
				}
				idx++
				ans[idx] = i
			}
		}

		for i:=1; i<=idx; i++ {
			fmt.Printf("%d ", ans[i])
		}
		fmt.Println()
	}
}
