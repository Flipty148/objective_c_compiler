@class InOutFuncs, NSArray, NSString;

@implementation MyClass1 : NSObject
@end

@implementation MyClass2 : MyClass1
- (void) func {
    return;
}
@end

@implementation MyClass3 : NSObject
@end

@implementation MyClass4 : NSObject
{
    int a;
}
@end

@implementation MyClass5 : MyClass4

- (void) func {
    a = 10;
}
@end

@implementation MyClass6 : NSObject
{
    MyClass4 *obj;
}

- (void) func {
    obj = [MyClass4 new];
    //obj->a = 15; //Ошибка
}
@end

@implementation MyClass7 : NSObject
- (void) print {
    [InOutFuncs printCharArray: "call method print from class 'MyClass7'"];
}
@end

@implementation MyClass8 : MyClass7
- (void) print {
    [InOutFuncs printCharArray: "call method print from class 'MyClass8'"];
}
@end

@implementation MyClass9 : MyClass7
- (void) print {
    [InOutFuncs printCharArray: "call method print from class 'MyClass9'"];
    [super print];
}
@end

@implementation MyClass10 : NSObject
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

@implementation MyClass : NSObject
@end

@implementation Fibonacci : NSObject

+ (int) nElem: (int) number {
    if (number == 1)
        return 1;
    else if (number == 2)
        return 1;
    else 
        return [self nElem: number - 1] + [self nElem: number - 2];
}
@end

int main() {
    //---------- Do While ----------
    int arrSize = 10;
    int i;
    
    int arr1[arrSize];
    [InOutFuncs printCharArray: "Input arr1:"];
    for (i = 0; i < arrSize; i = i + 1) {
        arr1[i] = [InOutFuncs readInt];
    }
    
    int j;
    int tmp;
    i = 0;
    do {
        j = 0;
        do {
            if (arr1[i] > arr1[j]) {
                tmp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = tmp; 
            }
            j = j + 1;
        }
        while (j < arrSize);
        i = i + 1;
    }
    while (i < arrSize);
    
    
    [InOutFuncs printCharArray: "\nOutput arr1:"];
    for (i=0; i < arrSize; i = i + 1) {
        [InOutFuncs printInt: arr1[i]];
    }

    //---------- For ----------
    int arr2[arrSize];
    [InOutFuncs printCharArray: "Input arr2: \n"];
    for (i = 0; i < arrSize; i = i + 1) {
        arr2[i] = [InOutFuncs readInt];
    }
    
    for (i = 0; i<arrSize; i = i + 1) {
        for (j = 0; j < arrSize; j = j + 1) {
            if (arr2[i] > arr2[j]) {
                tmp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = tmp;
            }
        }
    }
    
    [InOutFuncs printCharArray: "\nOutput arr2: \n"];
    for (i=0; i < arrSize; i = i + 1) {
        [InOutFuncs printInt: arr2[i]];
    }

    //---------- While ----------
    int arr3[arrSize];
    [InOutFuncs printCharArray: "Input arr3:"];
    for (i = 0; i < arrSize; i = i + 1) {
        arr3[i] = [InOutFuncs readInt];
    }
    
    i = 0;
    while (i < arrSize) {
        j = 0;
        while (j < arrSize) {
            if (arr3[i] > arr3[j]) {
                tmp = arr3[i];
                arr3[i] = arr3[j];
                arr3[j] = tmp; 
            }
            j = j + 1;
        }
        i = i + 1;
    }
    
    
    [InOutFuncs printCharArray: "\nOutput arr3:"];
    for (i=0; i < arrSize; i = i + 1) {
        [InOutFuncs printInt: arr3[i]];
    }

    //---------- ClassTypesCastes ----------
    MyClass1 *obj1 = [MyClass1 new];
    MyClass2 *obj2 = obj1;
    
    MyClass2 *obj3 = [MyClass2 new];
    MyClass2 *obj4 = obj3;

    //---------- FastEnumeration(Foreach) ----------
    NSArray *nsarr = [NSArray array];
    nsarr = [nsarr arrayByAddingObject: @"first"];
    nsarr = [nsarr arrayByAddingObject: @"second"];
    nsarr = [nsarr arrayByAddingObject: @"third"];
    NSArray *nsarr1 = [NSArray array];
    nsarr1 = [nsarr1 arrayByAddingObject: @"four"];
    nsarr1 = [nsarr1 arrayByAddingObject: @"five"];
    nsarr1 = [nsarr1 arrayByAddingObject: @"six"];
    
    for (NSString *elem in nsarr)
    {
        [InOutFuncs printNSString:elem];
        for (NSString *el in nsarr1)
        {
            [InOutFuncs printNSString:el];
        }
    }

    //---------- Fibobanacci ----------
    [InOutFuncs printCharArray: "Input number for fibonacci:"];
    int n = [InOutFuncs readInt];
    [InOutFuncs printInt: [Fibonacci nElem: n]];

    //---------- If ----------
    int a;
    int b;
    int c;
    int d;
    
    [InOutFuncs printCharArray: "Input a:"];
    a = [InOutFuncs readInt];
    
    [InOutFuncs printCharArray: "Input b:"];
    b = [InOutFuncs readInt];
    
    [InOutFuncs printCharArray: "Input c:"];
    c = [InOutFuncs readInt];
    
    [InOutFuncs printCharArray: "Input d:"];
    d = [InOutFuncs readInt];
    

    
    if (a == b) {
        [InOutFuncs printCharArray: "a == b"];
    }
    else {
        [InOutFuncs printCharArray: "a != b"];
    }
    
    if (a == b) {
        [InOutFuncs printCharArray: "a == b"];
    }
    
    if (a == b) {
        
    }
    else {
        [InOutFuncs printCharArray: "a != b"];
    }
    
    if (a == b) {
        
    }
    else {
        
    }
    
    if (a == b)
        [InOutFuncs printCharArray: "a == b"];
    else
        [InOutFuncs printCharArray: "a != b"];
        
    if (a == b)
        [InOutFuncs printCharArray: "a == b"];
        
    MyClass *obj;
    // obj = [MyClass new];
    
    if (a == b) {
        if (obj) {
            [InOutFuncs printCharArray: "a == b, true"];
        }
        else {
            [InOutFuncs printCharArray: "a == b, false"];
        }
    }
    else {
        if (obj) {
            [InOutFuncs printCharArray: "a != b, true"];
        }
        else {
            [InOutFuncs printCharArray: "a != b, false"];
        }
    }
    
    if (a == b) {
        [InOutFuncs printCharArray: "a == b"];
    }
    else if (c < d) {
        [InOutFuncs printCharArray: "c < d"];
    }
    else {
        [InOutFuncs printCharArray: "a != b, c >= d"];
    }

    //---------- InstanceVariable ----------
    MyClass4 *obj4inst = [MyClass4 new];
    obj4inst->a = 20;
    [InOutFuncs printInt: obj4inst->a];

    //---------- OOP ----------
    MyClass7 *obj7 = [MyClass7 new];
    MyClass8 *obj8 = [MyClass8 new];
    MyClass9 *obj9 = [MyClass9 new];
    
    MyClass7 *objects[] = { obj7, obj8, obj9 };
    
    for (i=0; i<3; i = i + 1) {
        [objects[i] print];
    }

    //---------- PrimitiveTypesCastsAndOperations ----------
    a = 10 + 20;
    b = 10 + 'a';
    c = 'a' + 20;
    d = 'a' + 'b';
    char e = 10 + 20;
    char f = 10 + 'a';
    char g = 'a' + 10;
    char h = 'a' + 'b';
    int a1 = 10 - 20;
    int b1 = 10 - 'a';
    int c1 = 'a' - 20;
    int d1 = 'a' - 'b';
    int a2 = 10 * 20;
    int b2 = 10 * 'a';
    int c2 = 'a' * 20;
    int d2 = 'a' * 'b';
    int a3 = 10 / 20;
    int b3 = 10 / 'a';
    int c3 = 'a' / 20;
    int d3 = 'a' / 'b';
    int a4 = 10 == 20;
    int b4 = 10 == 'a';
    int c4 = 'a' == 20;
    int d4 = 'a' == 'b';
    int a5 = 10 != 20;
    int b5 = 10 != 'a';
    int c5 = 'a' != 20;
    int d5 = 'a' != 'b';
    int a6 = 10 < 20;
    int b6 = 10 < 'a';
    int c6 = 'a' < 20;
    int d6 = 'a' < 'b';
    int a7 = 10 > 20;
    int b7 = 10 > 'a';
    int c7 = 'a' > 20;
    int d7 = 'a' > 'b';
    int a8 = 10 <= 20;
    int b8 = 10 <= 'a';
    int c8 = 'a' <= 20;
    int d8 = 'a' <= 'b';
    int a9 = 10 >= 20;
    int b9 = 10 >= 'a';
    int c9 = 'a' >= 20;
    int d9 = 'a' >= 'b';
    
    [InOutFuncs printCharArray: "Plus"];
    [InOutFuncs printInt: a];
    [InOutFuncs printInt: b];
    [InOutFuncs printInt: c];
    [InOutFuncs printInt: d];
    [InOutFuncs printChar: e];
    [InOutFuncs printChar: f];
    [InOutFuncs printChar: g];
    [InOutFuncs printChar: h];
    
    [InOutFuncs printCharArray: "\nMinus"];
    [InOutFuncs printInt: a1];
    [InOutFuncs printInt: b1];
    [InOutFuncs printInt: c1];
    [InOutFuncs printInt: d1];
    
    [InOutFuncs printCharArray: "\nMul"];
    [InOutFuncs printInt: a2];
    [InOutFuncs printInt: b2];
    [InOutFuncs printInt: c2];
    [InOutFuncs printInt: d2];
    
    [InOutFuncs printCharArray: "\nDiv"];
    [InOutFuncs printInt: a3];
    [InOutFuncs printInt: b3];
    [InOutFuncs printInt: c3];
    [InOutFuncs printInt: d3];
    
    [InOutFuncs printCharArray: "\nEqual"];
    [InOutFuncs printInt: a4];
    [InOutFuncs printInt: b4];
    [InOutFuncs printInt: c4];
    [InOutFuncs printInt: d4];
    
    [InOutFuncs printCharArray: "\nNotEqual"];
    [InOutFuncs printInt: a5];
    [InOutFuncs printInt: b5];
    [InOutFuncs printInt: c5];
    [InOutFuncs printInt: d5];
    
    [InOutFuncs printCharArray: "\nLess"];
    [InOutFuncs printInt: a6];
    [InOutFuncs printInt: b6];
    [InOutFuncs printInt: c6];
    [InOutFuncs printInt: d6];
    
    [InOutFuncs printCharArray: "\nGreater"];
    [InOutFuncs printInt: a7];
    [InOutFuncs printInt: b7];
    [InOutFuncs printInt: c7];
    [InOutFuncs printInt: d7];
    
    [InOutFuncs printCharArray: "\nLessEqual"];
    [InOutFuncs printInt: a8];
    [InOutFuncs printInt: b8];
    [InOutFuncs printInt: c8];
    [InOutFuncs printInt: d8];
    
    [InOutFuncs printCharArray: "\nGreaterEqual"];
    [InOutFuncs printInt: a9];
    [InOutFuncs printInt: b9];
    [InOutFuncs printInt: c9];
    [InOutFuncs printInt: d9];

    //---------- RefValue ----------
    Test *test = [Test new];
    
    [InOutFuncs printCharArray: "Test number"];
    int num = 4;
    [InOutFuncs printInt: num];
    [test testNumber: num];
    [InOutFuncs printInt: num];
    
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
    MyClass10 *obj10 = [MyClass10 new];
    [obj10 setA: 10];
    [InOutFuncs printInt: obj10->a];
    [test testObject: obj10];
    [InOutFuncs printInt: obj10->a];
}

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

- (void) testObject: (MyClass10*) o {
    [o setA: 15];
}
@end
