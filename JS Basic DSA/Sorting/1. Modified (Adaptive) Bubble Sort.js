// Adaptive Bubble Sort or Modified Bubble Sort
function bubbleSort(array) {
    let flag;

    for (let round = 1; round < array.length; round++) {
        flag = 0; // flag for explicit adaptive

        for (let index = 0; index < array.length - round; index++) {
            if (array[index] > array[index + 1]) {
                let temp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = temp;
                flag = 1;
            }
        }

        if (flag === 0) {
            return; // no swapping → already sorted
        }
    }
}


let array = [10, 5, 15, 20];
bubbleSort(array);

console.log("Array after Sorting:", array.join("  "));
