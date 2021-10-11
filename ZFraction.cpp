#include "ZFraction.h"

using namespace std;

ZFraction::ZFraction():numerateur(0),denominateur(1)
{}

ZFraction::ZFraction(int const num):numerateur(num),denominateur(1)
{}

ZFraction::ZFraction(int const num,int const den):numerateur(num),denominateur(den)
{
    if (den==0)
       denominateur=1;
    simplifier();
}

ZFraction::ZFraction(string fract)
{
    int n,m,b;
    string num,den;
    b=fract.find("/");
    if (b<0 && b>=(int)fract.size())
    {
        istringstream s(fract);
        s >> n;
        m=1;
    }
    else
    {
        for (int i=0;i<b;i++)
           num+=fract[i];
        for (unsigned int i=b+1;i<fract.size();i++)
           den+=fract[i];
        istringstream s(num),t(den);
        s >> n ;
        t >> m;
        if (m==0) m=1;
    }
    numerateur=n;
    denominateur=m;
    simplifier();
}

ZFraction::~ZFraction()
{}

void ZFraction::simplifier()
{
    int d=pgcd(numerateur,denominateur);
    numerateur/=d;
    denominateur/=d;
}



int ZFraction::num() const
{
    return numerateur;
}

int ZFraction::den() const
{
    return denominateur;
}

ostream& operator << (ostream& f,ZFraction const& z)
{
    if (z.den()==0)
       f << "\n\tERREUR:il y a 0 comme d\202nominateur\n";
    else
    {

        if (z.num()*z.den()<0)
            f << "-" << fabs(z.num());
        else
            f << fabs(z.num());
        if (z.den()!=1 && z.den()!=-1)
            cout << "/" << fabs(z.den());
    }
    return f;
}


ZFraction operator+ (ZFraction const& a,ZFraction const& b)
{
    ZFraction s;
    s.numerateur=a.num()*b.den()+b.num()*a.den();
    s.denominateur=a.den()*b.den();
    s.simplifier();
    return s;
}

ZFraction operator- (ZFraction const& a)
{
    ZFraction s;
    s.numerateur=-a.num();
    s.denominateur=a.den();
    s.simplifier();
    return s;
}

ZFraction operator- (ZFraction const& a,ZFraction const& b)
{
    ZFraction s;
    s= a+(-b);
    return s;
}









int pgcd(int a, int b)
{
    int r,c,s,p;
    if (a<b)
    {
       c=a;
       a=b;
       b=c;
    }
    if (b==1)
        p=1;
    else
    {
    r=a%b;
    if (r==0)
       p=b;
    else
    {
        do
        {
           s=r;
           a=b;
           b=r;
           r=a%b;
        }
        while (r!=0);
        p=s;
    }
    }
    return (p);
}
