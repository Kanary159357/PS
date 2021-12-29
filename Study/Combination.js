function combination(arr, num) {
	if (num == 1) {
		return arr.map((e) => e);
	}
	let result = [];
	for (let i = 0; i < arr.length; i++) {
		let fixed = arr[i];
		let rest = arr.slice(i + 1);
		let combinationRest = combination(rest, num - 1);
		let attached = combinationRest.map((e) => [fixed, ...e]);
		result.push(attached);
	}

	return result;
}

console.log(combination(['A', 'B', 'C'], 2));
