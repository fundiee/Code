function insertionSort(array) {
    for (let round = 1; round < array.length; round++) {
        let temp = array[round];
        let index = round - 1;

        while (index >= 0 && array[index] > temp) {
            array[index + 1] = array[index];
            index--;
        }

        array[index + 1] = temp;
    }
}

let array = [8, 6, 5, 9];
insertionSort(array);

console.log("Sorted array:", array.join("  "));