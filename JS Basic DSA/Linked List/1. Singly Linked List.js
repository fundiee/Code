class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class SLL {
    #head;
    constructor() {
        this.head = null;
    }

    isEmpty() {
        return this.head === null;
    }

    insertAtStart(data) {
        if (this.head === null) {
            this.head = new Node(data);
        } else {
            let temp = new Node(data);
            temp.next = this.head;
            this.head = temp;
        }
    }

    insertAtLast(data) {
        if (this.head === null) {
            this.head = new Node(data);
        } else {
            let temp = this.head;
            while (temp.next !== null) {
                temp = temp.next;
            }
            temp.next = new Node(data);
        }
    }

    // helper function
    searchNode(key) {
        let temp = this.head;
        while (temp !== null) {
            if (temp.data === key) {
                return temp;
            }
            temp = temp.next;
        }
        return null;
    }

    insertAfter(key, data) {
        let searchedNode = this.searchNode(key);
        if (searchedNode !== null) {
            if (searchedNode.next === null) {
                searchedNode.next = new Node(data);
            } else {
                let temp = new Node(data);
                temp.next = searchedNode.next;
                searchedNode.next = temp;
            }
        } else {
            console.log("Node not found!");
        }
    }

    show() {
        let temp = this.head;
        let result = "Linked List: ";
        while (temp !== null) {
            result += temp.data + "  ";
            temp = temp.next;
        }
        console.log(result);
        console.log("---------------------------------------");
    }

    deleteFirst() {
        if (this.head !== null) {
            if (this.head.next === null) {
                // delete only node
                this.head = null;
            } else {
                // delete first node
                this.head = this.head.next;
            }
        } else {
            console.log("Linked List is already empty!");
        }
    }

    deleteLast() {
        if (this.head !== null) {
            if (this.head.next === null) {
                // delete only node
                this.head = null;
            } else {
                // delete last node
                let temp = this.head;
                while (temp.next.next !== null) {
                    temp = temp.next;
                }
                temp.next = null;
            }
        } else {
            console.log("Linked List is already empty!");
        }
    }

    deleteNode(key) {
        let delNode = this.searchNode(key);

        if (delNode !== null) {
            // first node
            if (delNode === this.head) {
                this.head = this.head.next;
            }
            // deleting any middle or last node
            else {
                let temp = this.head;
                while (temp.next !== delNode) {
                    temp = temp.next;
                }
                temp.next = delNode.next;
            }
        } else {
            console.log("Node doesn't Exist!");
        }
    }

    deleteSLL() {
        // JS garbage collector handles deletion
        this.head = null;
    }
}


let list = new SLL();

list.insertAtStart(20);
list.insertAtLast(30);
list.insertAtLast(50);
list.insertAtStart(10);
list.insertAfter(50, 60);
list.insertAfter(30, 40);
list.show();

list.deleteFirst();
list.deleteLast();
list.show();

list.deleteNode(30);
list.show();

list.deleteNode(40);
list.show();

list.deleteNode(20);
list.show();

list.deleteNode(50);
list.show();