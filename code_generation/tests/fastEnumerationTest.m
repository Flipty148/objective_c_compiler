@class InOutFuncs, NSArray, NSString;
int main() {
    NSArray *arr = [NSArray array];
    arr = [arr arrayByAddingObject: @"first"];
    arr = [arr arrayByAddingObject: @"second"];
    arr = [arr arrayByAddingObject: @"third"];
    NSArray *arr1 = [NSArray array];
    arr1 = [arr1 arrayByAddingObject: @"four"];
    arr1 = [arr1 arrayByAddingObject: @"five"];
    arr1 = [arr1 arrayByAddingObject: @"six"];

    NSArray *arr2 = [NSArray array];
    arr2 = [arr2 arrayByAddingObject: @"seven"];
    arr2 = [arr2 arrayByAddingObject: @"eight"];
    arr2 = [arr2 arrayByAddingObject: @"nine"];

    // NSString *elem;
    for (NSString *elem in arr)
    {
        [InOutFuncs printNSString:elem];
        for (NSString *e in arr1)
        {
            [InOutFuncs printNSString:e];
            //arr1 = [arr1 arrayByAddingObject: @"test"];
            arr1 = arr2;
        }
    }
}
