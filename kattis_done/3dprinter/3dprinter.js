'use strict'
const readline = require('readline');


const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

rl.on('line', (line) => {
	var nums = line.split(' ');
	let n = parseInt(nums[0]);
	let d = [];
	for (let i = 0; i < n + 1; i++) {
		d.push([]);
		for (let j = 0; j < n + 1; j++) {
			d[i].push(-1);
		}
	}
	function recurse(printer, statue) {
		if (printer >= statue) return 1;
		if (d[printer][statue] == -1) {
			d[printer][statue] = Math.min(recurse(printer * 2, statue), recurse(printer, statue - printer))
		}
		return 1 + d[printer][statue];
	}
	console.log(recurse(1, n));
});