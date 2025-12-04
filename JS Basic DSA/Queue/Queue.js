class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class Queue {
    #tail;
    constructor() {
        this.tail = null;
    }

    isEmpty() {
        if (this.tail === null) {
            return true;
        } else {
            return false;
        }
    }

    enQueue(data) {
        if (this.tail === null) {
            this.tail = new Node(data);
            this.tail.next = this.tail;
        } else {
            const temp = new Node(data);
            temp.next = this.tail.next;
            this.tail.next = temp;
            this.tail = temp;
        }
    }

    deQueue() {
        if (this.tail !== null) {
            if (this.tail.next === this.tail) {
                // only one element
                this.tail = null;
            } else {
                const temp = this.tail.next;
                this.tail.next = temp.next;
            }
        } else {
            console.log("Queue is already empty!");
        }
    }

    showQueue() {
        let result = "Queue: ";
        if (this.tail !== null) {
            let temp = this.tail.next;

            while (temp !== this.tail) {
                result += temp.data + "  ";
                temp = temp.next;
            }
            result += temp.data;
        }
        console.log(result);
        console.log("----------------------------------------");
    }

    deleteQueue() {
        this.tail = null;
    }
}

const q = new Queue();
q.enQueue(10);
q.enQueue(20);
q.enQueue(30);
q.enQueue(40);
q.showQueue();

if (q.isEmpty()) {
    console.log("Queue is Empty!");
} else {
    console.log("Queue is not Empty!");
}

q.deQueue();
q.deQueue();
q.showQueue();

q.deleteQueue();
q.showQueue();