function merge(A, l, mid, h) {
    let i = l, j = mid + 1, k = l;
    let auxiliary = new Array(h + 1);

    // Merging the two sorted lists
    while (i <= mid && j <= h) {
        if (A[i] <= A[j]) {  // stable merge
            auxiliary[k++] = A[i++];
        } else {
            auxiliary[k++] = A[j++];
        }
    }

    // Copy remaining elements (only one loop will run)
    while (i <= mid) {
        auxiliary[k++] = A[i++];
    }

    while (j <= h) {
        auxiliary[k++] = A[j++];
    }

    // Copy merged data back to original array
    for (let x = l; x <= h; x++) {
        A[x] = auxiliary[x];
    }
}

function mergeSort(A, l, h) {
    if (l < h) {
        let mid = Math.floor((l + h) / 2);
        mergeSort(A, l, mid);       // left half
        mergeSort(A, mid + 1, h);   // right half
        merge(A, l, mid, h);        // merge halves
    }
}

let array = [4, 2, 9, 7, 8, 3, 5, 2];

mergeSort(array, 0, array.length - 1);

console.log("Sorted Array:", array.join("  "));