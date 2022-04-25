#pragma once
#include <vector>
#include <bitset>
#include <string>
#include <iostream>
#define BINT_SIZE 32 //addcarry and subborrow need corection if modified

typedef std::bitset<BINT_SIZE> bint;

class apfloat
{
public:
	apfloat(std::string initvalue, unsigned int size);
	~apfloat();
	friend apfloat operator>>(const apfloat &A,uint shift);
	friend apfloat operator<<(const apfloat &A,uint shift);
	friend apfloat operator+(const apfloat &A,const apfloat &B);
	friend apfloat operator-(const apfloat &A,const apfloat &B);
	friend apfloat operator*(const apfloat &A,const apfloat &B);
	friend apfloat operator/(const apfloat &A,const apfloat &B);
	friend std::ostream& operator<<(std::ostream& os, const apfloat &A);
	int size() {return float_segments.size();};
	void flipsign() {sign=!sign;}

private:
	std::vector<bint> float_segments;
	bool sign;
};

bint addcarry(bint a, bint b, bool *carry);//add bint a and b with carry

bint subborrow(bint a, bint b, bool *borrow);//substract b from a with borrow

std::string strflip(std::string str);

std::string binttostr(bint a);