@class InOutFuncs;
@implementation MyClass1 : NSObject

 + (id) new
 {
    return [super new];
 }
@end

int main()
{
    [InOutFuncs printInt:10];
    [InOutFuncs printInt: 10 + 20];
    [InOutFuncs printInt:10 - 20];
    [InOutFuncs printInt:20 - 10];
    [InOutFuncs printInt:10 * 30];
    [InOutFuncs printInt:40 / 10];
    [InOutFuncs printInt:40 / 3];
    [InOutFuncs printInt:-15];
    [InOutFuncs printInt:+13];
    [InOutFuncs printInt: (10 + 20) / 2];
    [InOutFuncs printCharArray:"aaaaabbbbbccccc"];
    //[InOutFuncs printNSString:@"nshello"];
    [InOutFuncs printInt:9 == 9];
    [InOutFuncs printInt:11 != 11];
    [InOutFuncs printInt:113 > 110];
    [InOutFuncs printInt:243 < 15];
    [InOutFuncs printInt:513 <= 513];
    [InOutFuncs printInt:5 >= 5];
    [MyClass1 new];
}
