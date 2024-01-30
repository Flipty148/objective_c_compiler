@class InOutFuncs;
int main() {
    int arrSize;
    int i;
    [InOutFuncs printCharArray: "Input array size"];
    arrSize = [InOutFuncs readInt];

    int arr[arrSize];
    [InOutFuncs printCharArray: "Input arr:"];
    for (i = 0; i < arrSize; i = i + 1) {
        arr[i] = [InOutFuncs readInt];
    }
    
    int j;
    i = 0;
    int tmp;
    while (i < arrSize) {
        j = 0;
        while (j < i) {
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp; 
            }
            j = j + 1;
        }
        i = i + 1;
    }
    
    
    [InOutFuncs printCharArray: "\nOutput arr:"];
    for (i=0; i < arrSize; i = i + 1) {
        [InOutFuncs printInt: arr[i]];
    }
}
