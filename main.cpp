#include "ZFraction.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    ZFraction a, b(5), c(-2,+3), d("-124/24");
    cout << "a=" << a <<endl;
    cout << "b=" << b <<endl;
    cout << "c=" << c <<endl;
    cout << "d=" << d <<endl;

    cout << "\n======"<< c+d+b  << "============="<<-(c+d);
    int x=452,y=124;
    cout << "\npgcd=" << pgcd(x,y) << "  x=" << x;
    return 0;
}
