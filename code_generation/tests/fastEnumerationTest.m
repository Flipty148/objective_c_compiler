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

    // NSString *elem;
    for (NSString *elem in arr)
    {
        [InOutFuncs printNSString:elem];
        for (NSString *e in arr1)
        {
            [InOutFuncs printNSString:e];
        }
    }
}
