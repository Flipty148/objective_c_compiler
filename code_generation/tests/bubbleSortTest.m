@class InOutFuncs;

int main() {
    int arrSize = 10;
    int i;
        
    int arr[arrSize];
    [InOutFuncs printCharArray: "Input arr: \n"];
    for (i = 0; i < arrSize; i = i + 1) {
        arr[i] = [InOutFuncs readInt];
    }
    
    for (i = 0; i<arrSize; i = i + 1) {
        for (int j = 0; j < arrSize; j = j + 1) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    
    [InOutFuncs printCharArray: "\nOutput arr: \n"];
    for (i=0; i < arrSize; i = i + 1) {
        [InOutFuncs printInt: arr[i]];
    }
}