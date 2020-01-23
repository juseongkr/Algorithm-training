package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var bufin = bufio.NewReader(os.Stdin)
var bufout = bufio.NewWriter(os.Stdin)
var n, m, l, k int
var num []int

func check(mid int) bool {
	ret := 0
	for i:=0; i<len(num)-1; i++ {
		ret += (num[i+1] - num[i] - 1) / mid;
	}
	return ret > m
}

func main() {
	defer bufout.Flush()
	fmt.Fscan(bufin, &n, &m, &l)

	for i:=0; i<n; i++ {
		fmt.Fscan(bufin, &k)
		num = append(num, k)
	}
	num = append(num, 0)
	num = append(num, l)

	sort.Ints(num)

	x := 0
	y := l
	for {
		if x > y {
			break
		}
		mid := (x+y)/2
		if check(mid) {
			x = mid+1;
		} else {
			y = mid-1;
		}
	}
	fmt.Println(x)
}
