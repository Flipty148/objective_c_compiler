@class InOutFuncs, NSString;
@implementation MyClass1 : NSObject
{
    int a;
}

//  + (id) new
//  {
//     return [super new];
//  }

- (void) setA: (int) value
{
    a = value;
}

- (void) print{
    [InOutFuncs printCharArray:"print"];
}

@end

int main()
{
    // [InOutFuncs printInt:10];
    // [InOutFuncs printInt: 10 + 20];
    // [InOutFuncs printInt:10 - 20];
    // [InOutFuncs printInt:20 - 10];
    // [InOutFuncs printInt:10 * 30];
    // [InOutFuncs printInt:40 / 10];
    // [InOutFuncs printInt:40 / 3];
    // [InOutFuncs printInt:-15];
    // [InOutFuncs printInt:+13];
    // [InOutFuncs printInt: (10 + 20) / 2];
    // [InOutFuncs printCharArray:"aaaaabbbbbccccc"];
    // [InOutFuncs printNSString:@"nshello"];
    // [InOutFuncs printInt:9 == 9];
    // [InOutFuncs printInt:11 != 11];
    // [InOutFuncs printInt:113 > 110];
    // [InOutFuncs printInt:243 < 15];
    // [InOutFuncs printInt:513 <= 513];
    // [InOutFuncs printInt:5 >= 5];
    MyClass1 *obj;
    // // [obj print];
    obj = [MyClass1 new];
    // // [obj setA:10];
    // // [InOutFuncs printInt:40578];
    // // int a;
    // // a = 5;
    // // [InOutFuncs printInt:a];
    // // [InOutFuncs printInt: obj->a];
    // // obj->a = 15;
    // [InOutFuncs printInt:obj->a];

    // int arr[10];
    // arr[0] = 1;
    // [InOutFuncs printInt:arr[0]];

    // int b;
    // b = 'b';
    // [InOutFuncs printInt:b];

    // char c;
    // c = 98;
    // [InOutFuncs printChar:c];

    // int d;
    // [InOutFuncs printInt:d];

    // char arrChar[10];
    // [InOutFuncs printInt:arrChar[0]];

    // char a[10] = {'a', 'b', 'c'};
    // [InOutFuncs printCharArray:a];
    // int a = [InOutFuncs readInt];
    // [InOutFuncs printInt:a];

    // if (obj) {

    // }
    // else {

    // }

    // int a = 31;
    // char b = 31;
    // if (a == b) {
    //     [InOutFuncs printCharArray:"a == b"];
    // }
    // else {
    //     [InOutFuncs printCharArray:"a != b"];
    // }

    // int i = 1;
    // while (i < 10) {
    //     [InOutFuncs printInt:i];
    //     i = i +1;
    // }

    // int i = 1;
    // do {
    //     [InOutFuncs printInt:i];
    //     i = i +1;
    // } while (i < 10);

    // for (int i = 0; i < 10; i = i + 1) {
    //     [InOutFuncs printInt:i];
    // }

    NSString *str = @"hello";
    [InOutFuncs printNSString:str];
    [InOutFuncs printNSString:@"test"];
}
