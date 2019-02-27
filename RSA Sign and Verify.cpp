#include "stdafx.h"
#include <math.h>
#include<iostream>
#include<string>

using namespace std;
long long Sign(long long, long long, long long);
bool Verify(long long,long long,long long,long long);
long long modexp(long long, long long, long long);
long long modmult(long long, long long, long long);



int main()
{
	int id;
	cout << "Enter ID: " << endl;
	cin >> id;
	cout << "\n" << id << " is your ID" << endl;
	long long J = Sign(id, 3,33);

	

	cout << "ID to power of D mod N: J= " << J << endl;

	bool verify= Verify(33, 7, 18, id);
	if (verify == true)
	{
		cout << "Verified!" << endl;
	}
	else
	{
		cout << "Not Verified!" << endl;
	}

	string p;
	cin >> p;
    return 0;
}



long long Sign(long long M, long long d, long long N)
{
	//long long x = (long long)pow((double)M, (double)d);
	//x = x % N;

	long long x = modexp(M, d, N);
	return x;
}

bool Verify(long long N, long long e, long long J, long long M)
{
	//long long x = (long long)pow((double)J, (double)e);
	//x = x % N;
	long long x = modexp(J, e, N);
	cout << "Raise J to power of e mod N gives you: " << x << endl;
	if (x == M)
	{
		return true;

	}

	else if (x != M)
	{
		return false;
	}

	else
	{
//		cout << "error" << endl;
	}
	return false;
}




long long modmult(long long a, long long b, long long N)
{

	long long c;		// Takes modulo then multiplies then modulo again
	a = a % N;
	b = b % N;
	return c = (a * b) % N;
}


long long modexp(long long x, long long  y, long long  N)
{
	long long c, d, e;
	if (y == 0)
	{
		return 1;
	}
	d = y / 2;					// Recursive function;

	c = modexp(x, d, N);

	if (y % 2 == 0)
	{
		return  (modmult(c, c, N));
	}
	else
	{
		return (x * modmult(c, c, N)) % N;
	}
}