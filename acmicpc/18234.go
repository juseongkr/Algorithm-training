package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Data struct {
	add int
	base int
}

var bufin = bufio.NewReader(os.Stdin)
var bufout = bufio.NewWriter(os.Stdin)
var n, t, x, y int
var vec []Data

func main() {
	defer bufout.Flush()
	fmt.Fscan(bufin, &n, &t);

	for i:=0; i<n; i++ {
		fmt.Fscan(bufin, &x, &y);
		vec = append(vec, Data{y, x});
	}

	sort.Slice(vec, func(i, j int) bool {
		if vec[i].add == vec[j].add {
			return vec[i].base < vec[j].base
		} else {
			return vec[i].add < vec[j].add
		}
	});

	var ans int64
	for i:=0; i<n; i++ {
		ans += int64(vec[i].base) + int64(vec[i].add) * int64(t-n+i)
	}

	fmt.Println(ans)
}
