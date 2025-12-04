class Customer {
    constructor(name, id) {
        this.name = name;
        this.id = id;
        this.next = null;
        this.prev = null;
    }
}

class List {
    constructor(name, id) {
        this.head = new Customer(name, id);
    }

    isEmpty() {
        return this.head === null;
    }

    insertAtStart(name, id) {
        const temp = new Customer(name, id);
        if (this.head !== null) {
            temp.next = this.head;
            this.head.prev = temp;
        }
        this.head = temp;
    }

    insertAtLast(name, id) {
        const temp = new Customer(name, id);
        if (this.head === null) {
            this.head = temp;
            return;
        }
        let last = this.head;
        while (last.next !== null) {
            last = last.next;
        }
        last.next = temp;
        temp.prev = last;
    }

    showList() {
        console.log("Customer id | Customer Name");
        let temp = this.head;
        while (temp !== null) {
            console.log(`${temp.id}         | ${temp.name}`);
            temp = temp.next;
        }
        console.log("----------------------------");
    }

    searchCustomer(id) {
        let temp = this.head;
        while (temp !== null) {
            if (temp.id === id) return temp;
            temp = temp.next;
        }
        return null;
    }

    insertAfter(customer, name, id) {
        if (!customer) return;
        const temp = new Customer(name, id);
        temp.next = customer.next;
        temp.prev = customer;
        if (customer.next !== null) {
            customer.next.prev = temp;
        }
        customer.next = temp;
    }

    deleteFirst() {
        if (this.head === null) return;
        const temp = this.head;
        this.head = this.head.next;
        if (this.head !== null) {
            this.head.prev = null;
        }
    }

    deleteLast() {
        if (this.head === null) return;

        let temp = this.head;
        if (temp.next === null) {
            this.head = null;
            return;
        }

        while (temp.next !== null) {
            temp = temp.next;
        }
        temp.prev.next = null;
    }

    deleteCustomer(id) {
        let temp = this.head;
        while (temp !== null) {
            if (temp.id === id) {
                if (temp.prev !== null) temp.prev.next = temp.next;
                else this.head = temp.next;

                if (temp.next !== null) temp.next.prev = temp.prev;
                return;
            }
            temp = temp.next;
        }
    }

    clearList() {
        this.head = null;
    }
}


const l1 = new List("Shaheer Sheraz", 102);
l1.showList();

l1.insertAtStart("Abdullah", 101);
l1.showList();

l1.insertAtLast("Talha Raza", 104);
l1.showList();

l1.insertAfter(l1.searchCustomer(102), "Fazal Shah", 103);
l1.showList();

l1.insertAtLast("Ahmed", 105);
l1.showList();

l1.deleteFirst();
l1.showList();

l1.deleteLast();
l1.showList();

l1.deleteCustomer(103);
l1.showList();

l1.clearList();
l1.showList();