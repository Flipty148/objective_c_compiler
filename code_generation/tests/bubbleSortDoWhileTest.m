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
        do {
            j = 0;
            do {
                if (arr[i] > arr[j]) {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp; 
                }
                j = j + 1;
            }
            while (j < i);
            i = i + 1;
        }
        while (i < arrSize);
        
        
        [InOutFuncs printCharArray: "\nOutput arr:"];
        for (i=0; i < arrSize; i = i + 1) {
            [InOutFuncs printInt: arr[i]];
        }
}