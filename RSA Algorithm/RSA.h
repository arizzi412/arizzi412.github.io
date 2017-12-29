#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <string>
#include "ModularArithmetic.h"

#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <string>
#include "ModularArithmetic.h"

using namespace std;

class RSA {
	private:
	mpz_class* pubKey;
	mpz_class* privKey;

	public:
	RSA(int n);
	RSA(int n, string privKeyFilename, string pubKeyFilename);
	RSA(string privKeyFilename, string pubKeyFilename);
	RSA(string pubKeyFilename);
	~RSA();
	mpz_class encrypt(string message);
	mpz_class decrypt(string data);
};

#endif
using namespace std;

class RSA {
	private:
	mpz_class* pubKey;
	mpz_class* privKey;

	public:
	RSA(int n);
	RSA(int n, string privKeyFilename, string pubKeyFilename);
	RSA(string privKeyFilename, string pubKeyFilename);
	RSA(string pubKeyFilename);
	~RSA();
	mpz_class encrypt(string message);
	mpz_class decrypt(string data);
};

#endif
