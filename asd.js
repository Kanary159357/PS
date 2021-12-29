class Node {
	constructor(val) {
		this.next = null;
		this.val = val;
	}
}

class NodeList {
	constructor(list) {
		this.head = null;
		this.length = 0;
		this.init(list);
	}

	init(list) {
		if (list == null) return;
		for (let i = 0; i < list.length; i++) {
			this.add(list[i]);
		}
	}

	add(val) {
		let node = new Node(val);
		let cur = this.head;
		if (this.length == 0) {
			this.head = node;
		} else {
			while (cur.next) {
				cur = cur.next;
			}
			cur.next = node;
		}

		this.length++;
	}

	display() {
		let cur = this.head;
		while (cur) {
			console.log(cur.val);
			cur = cur.next;
		}
	}
}

let list = new NodeList();
list.add(1);
list.display();

function bubblesort(arr) {
	for (let i = arr.length; i > 1; i++) {
		for (let j = 0; j < i; j++) {
			if (arr[j] < arr[j + 1]) {
				let temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j] = temp;
			}
		}
	}
}

function quicksort(arr) {}

function mergesort(arr) {
	if (arr.length == 1) return arr;
	let mid = parseInt(arr.length / 2);

	let left = arr.slice(0, mid);
	let right = arr.slice(mid, arr.length);

	return merge(mergesort(left), mergesort(right));

	function merge(left, right) {
		let result = [];
		while (left.length && right.length) {
			if (left[0] < right[0]) {
				result.push(left.shift());
			} else {
				result.push(right.shift());
			}
		}
		while (left.length) {
			result.push(left.shift());
		}
		while (right.length) {
			result.push(left.shift());
		}
		return result;
	}
	return;
}
