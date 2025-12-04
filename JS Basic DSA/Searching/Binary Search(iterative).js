function binarySearch(array, key) {
    let l = 0, h = array.length - 1;
    let mid = Math.floor((l + h) / 2);

    while (l <= h) {
        if (array[mid] === key) {
            return mid; // index
        } else if (array[mid] > key) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }

        mid = Math.floor((l + h) / 2);
    }

    return -1; // index
}


const array = [10, 20, 30, 40, 50, 60, 70, 80];

let num = parseInt(prompt("Enter a number to search: "));

let searchedNumIndex = binarySearch(array, num);

if (searchedNumIndex !== -1) {
    console.log("Searched Data Existed:", array[searchedNumIndex]);
} else {
    console.log("Data Not Found!");
}