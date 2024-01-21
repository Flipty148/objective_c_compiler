@class InOutFuncs;
int main() {
    int arrSize = 10;
    int i;
    
    int arr[arrSize];
    [InOutFuncs printCharArray: "Input arr:"];
    for (i = 0; i < arrSize; i = i + 1) {
        arr[i] = [InOutFuncs readInt];
    }
    
    int j;
    i = 0;
    while (i < arrSize) {
        j = 0;
        while (j < arrSize) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
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
