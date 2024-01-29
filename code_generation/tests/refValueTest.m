@class InOutFuncs, NSString;
@implementation MyClass1 : NSObject
{
    int a;
}
- (void) setA: (int) n {
    a = n;
}
@end

@interface Test : NSObject
- (void) testNumber: (int) n;
- (void) testArray: (int[]) a;
- (void) testString: (char []) c;
- (void) testNSString: (NSString*) s;
@end

@implementation Test
- (void) testNumber: (int) n {
    n = n + 10;
}

- (void) testArray: (int[]) a {
    a[0] = a[0] + 10;
}

- (void) testString: (char []) c {
    c[0] = 'a';
}

-(void) testNSString: (NSString*) s {
    s = @"test";
}

- (void) testObject: (MyClass1*) o {
    [o setA: 1587];
}
@end

int main ()
{
    Test *test = [Test new];
    
    [InOutFuncs printCharArray: "Test number"];
    int n = 4;
    [InOutFuncs printInt: n];
    [test testNumber: n];
    [InOutFuncs printInt: n];
    
    [InOutFuncs printCharArray: "\nTest array"];
    int arr[] = {1, 2, 3};
    [InOutFuncs printInt: arr[0]];
    [InOutFuncs printInt: arr[1]];
    [InOutFuncs printInt: arr[2]];
    [test testArray: arr];
    [InOutFuncs printInt: arr[0]];
    [InOutFuncs printInt: arr[1]];
    [InOutFuncs printInt: arr[2]];
    
    [InOutFuncs printCharArray: "\nTest string"];
    char str[] = "c str";
    [InOutFuncs printCharArray: str];
    [test testString: str];
    [InOutFuncs printCharArray: str];
    
    [InOutFuncs printCharArray: "\nTest NSString"];
    NSString *nsstr = @"nsstr";
    [InOutFuncs printNSString: nsstr];
    [test testNSString: nsstr];
    [InOutFuncs printNSString: nsstr];
    
    [InOutFuncs printCharArray: "\nTest object"];
    MyClass1 *obj = [MyClass1 new];
    [obj setA: 10];
    [InOutFuncs printInt: obj->a];
    [test testObject: obj];
    [InOutFuncs printInt: obj->a];
}