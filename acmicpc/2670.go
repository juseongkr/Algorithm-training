package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	var n int
	var k float64
	var num []float64
	bufin := bufio.NewReader(os.Stdin)
	bufout := bufio.NewWriter(os.Stdin)
	defer bufout.Flush()

	fmt.Fscan(bufin, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(bufin, &k)
		num = append(num, k)
	}

	ans := num[0]
	for i := 1; i < n; i++ {
		num[i] = math.Max(num[i], num[i-1]*num[i])
		ans = math.Max(ans, num[i])
	}

	fmt.Printf("%.3f", ans)
}
