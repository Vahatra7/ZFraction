#ifndef ZFRACTION_H_INCLUDED
#define ZFRACTION_H_INCLUDED
#include <iostream>
#include <sstream>
#include <cmath>

class ZFraction
{
    public:
       ZFraction();
       ZFraction(int const);
       ZFraction(int const,int const);
       ZFraction(std::string);
       ~ZFraction();

       void simplifier();

       int num() const;
       int den() const;



    protected:
       int numerateur,denominateur;

    friend ZFraction operator+ (ZFraction const&,ZFraction const&);
    friend ZFraction operator- (ZFraction const&);
    friend ZFraction operator- (ZFraction const&,ZFraction const&);
    friend ZFraction operator* (ZFraction const&,ZFraction const&);
    friend ZFraction operator/ (ZFraction const&,ZFraction const&);
};

std::ostream& operator << (std::ostream& ,ZFraction const&);
int pgcd(int ,int);

#endif // ZFRACTION_H_INCLUDED
