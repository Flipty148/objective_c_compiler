@class InOutFuncs, NSArray, NSString;
int main() {
    NSArray *arr = [NSArray array];
    arr = [arr arrayByAddingObject: @"first"];
    arr = [arr arrayByAddingObject: @"second"];
    arr = [arr arrayByAddingObject: @"third"];
    
    // NSString *elem;
    for (NSString *elem in arr)
    {
        [InOutFuncs printNSString:elem];
    }
}
