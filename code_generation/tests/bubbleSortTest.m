@class InOutFuncs;

int main() {
    int arrSize;
    int i;
    [InOutFuncs printCharArray: "Input array size"];
    arrSize = [InOutFuncs readInt];

    int arr[arrSize];
    [InOutFuncs printCharArray: "Input arr: \n"];
    for (i = 0; i < arrSize; i = i + 1) {
        arr[i] = [InOutFuncs readInt];
    }
    
    int tmp;
    for (i = 0; i<arrSize; i = i + 1) {
        for (int j = 0; j < i; j = j + 1) {
            if (arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    
    [InOutFuncs printCharArray: "\nSorted arr: \n"];
    for (i=0; i < arrSize; i = i + 1) {
        [InOutFuncs printInt: arr[i]];
    }
}