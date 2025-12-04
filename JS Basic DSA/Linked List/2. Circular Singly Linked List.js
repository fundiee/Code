class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class CSLL {
    #tail;
    constructor() {
        this.tail = null;
    }

    isEmpty() {
        return this.tail === null;
    }

    insertAtStart(data) {
        if (this.tail === null) {
            this.tail = new Node(data);
            this.tail.next = this.tail;
        } else {
            const temp = new Node(data);
            temp.next = this.tail.next;
            this.tail.next = temp;
        }
    }

    insertAtLast(data) {
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

    insertAfter(key, data) {
        if (this.tail !== null) {
            let temp = this.tail.next;
            while (temp !== this.tail) {
                if (temp.data === key) {
                    const newNode = new Node(data);
                    newNode.next = temp.next;
                    temp.next = newNode;
                    return;
                }
                temp = temp.next;
            }

            if (temp.data === key) {
                const newNode = new Node(data);
                newNode.next = temp.next;
                temp.next = newNode;
                this.tail = newNode;
            }
        }
    }

    show() {
        let result = "List: ";

        if (this.tail !== null) {
            let temp = this.tail.next;
            while (temp !== this.tail) {
                result += temp.data + "  ";
                temp = temp.next;
            }
            result += temp.data;
        }

        console.log(result);
    }

    deleteFirst() {
        if (this.tail !== null) {
            if (this.tail.next === this.tail) {
                this.tail = null;
            } else {
                const temp = this.tail.next;
                this.tail.next = this.tail.next.next;
            }
        }
    }

    deleteLast() {
        if (this.tail !== null) {
            if (this.tail.next === this.tail) {
                this.tail = null;
            } else {
                let temp = this.tail.next;
                while (temp.next !== this.tail) {
                    temp = temp.next;
                }
                temp.next = this.tail.next;
                this.tail = temp;
            }
        }
    }

    searchNode(data) {
        if (this.tail !== null) {
            let temp = this.tail.next;
            while (temp !== this.tail) {
                if (temp.data === data) return temp;
                temp = temp.next;
            }
            if (temp.data === data) return temp;
        }
        return null;
    }

    deleteNode(data) {
        const delNode = this.searchNode(data);
        if (delNode !== null) {

            if (this.tail.next === this.tail) {
                this.tail = null;
                return;
            }

            if (delNode === this.tail) {
                let temp = this.tail.next;
                while (temp.next !== this.tail) {
                    temp = temp.next;
                }
                temp.next = this.tail.next;
                this.tail = temp;
                return;
            }

            let temp = this.tail.next;
            while (temp.next !== delNode) {
                temp = temp.next;
            }
            temp.next = delNode.next;
        }
    }

    clearList() {
        if (this.tail !== null) {
            let temp = this.tail.next;
            while (temp !== this.tail) {
                temp = temp.next;
            }
            this.tail = null;
        }
    }
}


let list = new CSLL();
list.insertAtStart(30);
list.insertAtLast(40);
list.insertAtStart(20);
list.insertAtLast(50);
list.insertAtStart(10);
list.insertAtLast(60);

list.show();

list.insertAfter(10, 15);
list.show();

list.insertAfter(30, 35);
list.insertAfter(60, 65);
list.show();

list.deleteFirst();
list.deleteLast();
list.deleteFirst();
list.deleteLast();
list.show();

list.deleteNode(20);
list.deleteNode(50);
list.deleteNode(35);
list.show();