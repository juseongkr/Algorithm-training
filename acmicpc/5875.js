const readline = require('readline');

let input = [];
const read = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

let cnt = 0;
let x = 0;
let y = 0;
read.on('line', line => {
	input.push(line);
}).on('close', () => {
	const s = input[0];

	for (const c of s) {
		if (c === '(') {
			cnt++;
			x++;
		} else {
			cnt--;
			y++;
		}

		if (cnt < 2)
			x = 0;

		if (cnt < 0) {
			console.log(y);
			process.exit();
		}
	}
	console.log(x);
	process.exit();
});     
