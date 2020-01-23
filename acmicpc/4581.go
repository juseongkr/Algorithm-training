package main

import (
	"strings"
	"bufio"
	"fmt"
	"os"
)

var bufin = bufio.NewReader(os.Stdin)
var bufout = bufio.NewWriter(os.Stdin)

func main() {
	defer bufout.Flush()
	
	for {
		var s string
		A := 0
		Y := 0
		N := 0
		P := 0

		fmt.Fscan(bufin, &s)

		if strings.Compare(s, "#") == 0 {
			break
		}

		for _, i := range s {
			switch i {
			case 'N':
				N++
			case 'Y':
				Y++
			case 'A':
				A++
			case 'P':
				P++
			}
		}

		if A >= (len(s)+1)/2 {
			fmt.Println("need quorum")
		} else if Y > N {
			fmt.Println("yes")
		} else if Y < N {
			fmt.Println("no")
		} else {
			fmt.Println("tie")
		}
	}
}
