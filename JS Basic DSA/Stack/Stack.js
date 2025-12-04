class Node {
    constructor(item) {
        this.item = item;
        this.next = null;
    }
}

class Stack {
    #top = null;
    constructor(item) {
        this.top = new Node(item);
        this.size = 1;
    }

    isEmpty() {
        if (this.top === null) {
            return true;
        } else {
            return false;
        }
    }

    push(item) {
        if (this.top === null) {
            this.top = new Node(item);
            this.size++;
        } else {
            const temp = new Node(item);
            temp.next = this.top;
            this.top = temp;
            this.size++;
        }
    }

    stackSize() {
        return this.size;
    }

    peak() {
        if (this.top !== null) {
            console.log("Top Item: " + this.top.item);
        } else {
            console.log("Stack is Empty!");
        }
    }

    pop() {
        if (this.top !== null) {
            const temp = this.top;
            this.top = this.top.next;
            console.log("Poped Item: " + temp.item);
            this.size--;
        } else {
            console.log("Stack is Underflow!");
        }
    }

    clear() {
        this.top = null;
        this.size = 0;
        console.log("Stack is Cleared!");
        console.log("---------------------------");
    }
}


const s = new Stack(10);

if (s.isEmpty()) {
    console.log("Stack is Empty!");
} else {
    console.log("Stack is not Empty!");
}
console.log("---------------------------");

s.push(20);
s.peak();
console.log("---------------------------");

s.push(30);
s.push(40);
console.log("Stack Size: " + s.stackSize());
console.log("---------------------------");

s.pop();
s.pop();
s.pop();
console.log("---------------------------");

s.peak();
console.log("---------------------------");

s.clear();