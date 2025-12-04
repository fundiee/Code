class Student {
    constructor(rollno, name) {
        this.rollno = rollno;
        this.name = name;
        this.next = null;
        this.prev = null;
    }
}

class List {
    constructor(rollno, name) {
        this.head = new Student(rollno, name);
        this.head.next = this.head;
        this.head.prev = this.head;
    }

    isEmpty() {
        if (this.head === null) {
            return true;
        } else {
            return false;
        }
    }

    insertAtStart(rollno, name) {
        if (this.head === null) {
            this.head = new Student(rollno, name);
            this.head.next = this.head;
            this.head.prev = this.head;
        } else {
            const temp = new Student(rollno, name);
            temp.next = this.head;
            temp.prev = this.head.prev;
            this.head.prev.next = temp;
            this.head.prev = temp;
            this.head = temp;
        }
    }

    insertAtLast(rollno, name) {
        if (this.head === null) {
            this.head = new Student(rollno, name);
            this.head.next = this.head;
            this.head.prev = this.head;
        } else {
            const temp = new Student(rollno, name);
            temp.next = this.head;
            temp.prev = this.head.prev;
            this.head.prev.next = temp;
            this.head.prev = temp;
        }
    }

    showList() {
        if (this.head === null) {
            console.log("List is Empty!");
        } else {
            let temp = this.head;
            console.log("Roll Number    |   Name");
            while (temp.next !== this.head) {
                console.log(`${temp.rollno}   |   ${temp.name}`);
                temp = temp.next;
            }
            console.log(`${temp.rollno}   |   ${temp.name}`);
        }
        console.log("---------------------------------------------");
    }

    searchStudent(rollno) {
        if (this.head !== null) {
            let temp = this.head;
            while (temp.next !== this.head) {
                if (temp.rollno === rollno) return temp;
                temp = temp.next;
            }
            if (temp.rollno === rollno) return temp;
        }
        return null;
    }

    insertAfter(n, rollno, name) {
        if (n === null) {
            console.log("Student doesn't Exist!");
        } else {
            // only one student
            if (n.next === this.head && n.prev === this.head) {
                const temp = new Student(rollno, name);
                temp.next = this.head;
                temp.prev = n;
                n.next = temp;
                n.prev = temp;
            }
            // last node
            else if (n.next === this.head && n.prev !== this.head) {
                const temp = new Student(rollno, name);
                temp.next = this.head;
                temp.prev = n;
                n.next = temp;
                this.head.prev = temp;
            }
            // middle nodes
            else {
                const temp = new Student(rollno, name);
                temp.next = n.next;
                temp.prev = n;
                n.next.prev = temp;
                n.next = temp;
            }
        }
    }

    deleteFirst() {
        if (this.head !== null) {
            if (this.head.next === this.head) {
                this.head = null;
            } else {
                const temp = this.head;
                this.head.prev.next = this.head.next;
                this.head.next.prev = this.head.prev;
                this.head = this.head.next;
            }
        }
    }

    deleteLast() {
        if (this.head !== null) {
            if (this.head.next === this.head) {
                this.head = null;
            } else {
                const temp = this.head.prev;
                this.head.prev.prev.next = this.head;
                this.head.prev = this.head.prev.prev;
            }
        }
    }

    deleteStudent(s) {
        if (s !== null) {
            // only one student
            if (s.next === this.head && s.prev === this.head) {
                this.head = null;
            }
            // first node
            else if (s === this.head && s.next !== this.head) {
                s.prev.next = s.next;
                s.next.prev = s.prev;
                this.head = s.next;
            }
            // last node
            else if (s.next === this.head && s.prev !== this.head) {
                s.prev.next = this.head;
                s.next.prev = s.prev;
            }
            // middle node
            else {
                s.next.prev = s.prev;
                s.prev.next = s.next;
            }
        }
    }

    clearList() {
        this.head = null;
    }
}


const l1 = new List("23014198-002", "Asjad Hafeez");
l1.showList();

l1.insertAtStart("23014198-001", "Fazal Shah");
l1.showList();

l1.insertAtStart("23014198-004", "Talha Raza");
l1.showList();

l1.insertAfter(l1.searchStudent("23014198-002"), "23014198-003", "Syed Haroon Bukhari");
l1.showList();

l1.insertAtLast("23014198-005", "Ayesha Azhar");
l1.showList();

l1.deleteFirst();
l1.showList();

l1.deleteLast();
l1.showList();

l1.deleteStudent(l1.searchStudent("23014198-002"));
l1.showList();

l1.clearList();
l1.showList();
