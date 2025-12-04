class Heap {
    insert(array, index) {
        while (index > 0 && array[index] > array[Math.floor((index - 1) / 2)]) {
            let swap = array[index];
            array[index] = array[Math.floor((index - 1) / 2)];
            array[Math.floor((index - 1) / 2)] = swap;

            index = Math.floor((index - 1) / 2);
        }
    }

    createHeap(array) {
        for (let index = 1; index < array.length; index++) {
            this.insert(array, index);
        }
    }

    show(msg, array) {
        console.log(msg + array.join(" "));
        console.log('---------------------------------------------------');
    }

    deleteElement(heap, heapSize) {
        let index = 0;
        let deletedElement = heap[index];
        heap[index] = heap[heapSize - 1];

        let leftChildIndex = 2 * index + 1;
        let rightChildIndex = 2 * index + 2;
        let greaterChildIndex;

        while (leftChildIndex < heapSize) {
            if (rightChildIndex >= heapSize) {
                greaterChildIndex = leftChildIndex;
            } else {
                greaterChildIndex = heap[leftChildIndex] > heap[rightChildIndex] ? leftChildIndex : rightChildIndex;
            }

            if (heap[greaterChildIndex] > heap[index]) {
                let swap = heap[greaterChildIndex];
                heap[greaterChildIndex] = heap[index];
                heap[index] = swap;

                index = greaterChildIndex;
                leftChildIndex = 2 * index + 1;
                rightChildIndex = 2 * index + 2;
            } else {
                break;
            }
        }

        return deletedElement;
    }

    deleteHeap(array) {
        let heapSize = array.length;
        for (let i = 1; i < array.length; i++) {
            array[heapSize - 1] = this.deleteElement(array, heapSize);
            heapSize--;
        }
    }

    HeapSort(array) {
        this.createHeap(array);
        this.deleteHeap(array);
    }
}

// Testing
const array1 = [20, 30, 90, 60, 40, 50];
const h = new Heap();

h.show("Array1 before Heap: ",array1);

h.createHeap(array1);
h.show("Heap: ", array1);

h.deleteHeap(array1);
h.show("Array1 After Heap Deletion: ", array1);

const array2 = [20, 30, 110, 90, 60, 40, 50, 100, 70, 10, 80];
const hs = new Heap();
hs.HeapSort(array2);

hs.show("Heap Sort: ", array2);