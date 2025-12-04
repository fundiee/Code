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

const array = [20, 30, 110, 90, 60, 40, 50, 100, 70, 10, 80];
const h = new Heap();
h.HeapSort(array);

h.show("Heap Sort: ", array);