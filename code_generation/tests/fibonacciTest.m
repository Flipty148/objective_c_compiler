@class InOutFuncs;
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

@implementation Fib : Fibonacci
@end

int main ()
{
    [InOutFuncs printCharArray: "Input number:"];
    int n = [InOutFuncs readInt];
    [InOutFuncs printInt: [Fib nElem: n]];
    return 0;
}
