//Alessandro lab 2

#include "RSA.h"
#include "ModularArithmetic.h"
#include <iostream>
#include <fstream>
#include <gmpxx.h>

using namespace std;


	RSA::RSA(int n)
	{

		mpz_class p, q, N, s, e, d, relPrime;
		ModularArithmetic mod;

		privKey = new mpz_class[2]; // allocates dynamic array
		pubKey = new mpz_class[2];

		p = mod.genPrime(n);
		q = mod.genPrime(n);

		N = p * q;
		s = (p-1)*(q-1);


		e = mod.genPrime(n);
		mpz_gcd(relPrime.get_mpz_t(), s.get_mpz_t(), e.get_mpz_t()); // loops until relatively prime.



		 while (relPrime != 1)
			{
			e = mod.genPrime(n);
			mpz_gcd(relPrime.get_mpz_t(), s.get_mpz_t(), e.get_mpz_t());

			}



		mpz_invert(d.get_mpz_t(),e.get_mpz_t(),s.get_mpz_t());

		cout << N << " " << e << endl;

		cout << d << " this" << endl;
		privKey[0] = N;
		privKey[1] = d;


		pubKey[0] = N;
		pubKey[1] = e;


	}


	RSA::~RSA()
		{
			delete [] privKey;
			privKey = NULL;

			delete [] pubKey;
			pubKey = NULL;
		}




	RSA::RSA(int n, string privKeyFilename, string pubKeyFilename)

	{

		ofstream file;

		privKey = new mpz_class[2];
		pubKey = new mpz_class[2];

		mpz_class p, q, N, s, e, d, resultpriv[2],resultpub[2], relPrime;
		ModularArithmetic mod;

		p = mod.genPrime(n);
		q = mod.genPrime(n); // generates primes

		N = p * q;
		s = (p-1)*(q-1);


		e = mod.genPrime(n);
		mpz_gcd(relPrime.get_mpz_t(), s.get_mpz_t(), e.get_mpz_t());


		 while (relPrime != 1)  //loops until gcd is 1 (relatively prime)
			{
			e = mod.genPrime(n);
			mpz_gcd(relPrime.get_mpz_t(), s.get_mpz_t(), e.get_mpz_t());

			}


		mpz_invert(d.get_mpz_t(),e.get_mpz_t(),s.get_mpz_t()); // gets d which is inverse of e




		privKey[0] = N;
		privKey[1] = d;



		pubKey[0] = N;
		pubKey[1] = e;


		cout << N << " " << d << endl;

		file.open(pubKeyFilename.c_str());


		file << N << endl << e;




		file.close();





		file.open(privKeyFilename.c_str());

		file << N << endl << d << endl;

		file.close();


	}


	RSA::RSA(string privKeyFilename, string pubKeyFilename)
{

		privKey = new mpz_class[2];
		pubKey = new mpz_class[2];


		ifstream file;


		string strN, strd, stre , pubN;

		file.open(privKeyFilename.c_str());  // opens file and prints private and public keys

		file >> strN;
		file >> strd;



		mpz_class N(strN);
		mpz_class d(strd);


		privKey[0] = N;
		privKey[1] = d;


		file.close();


		file.open(pubKeyFilename.c_str());

		file >> pubN;

		file >> stre;

		mpz_class NN(pubN);
		mpz_class e(stre);


		pubKey[0] = NN;
		pubKey[1] = e;

		file.close();





}
	RSA::RSA(string pubKeyFilename)
{
		ifstream file;


		privKey = new mpz_class[2];
		pubKey = new mpz_class[2];

		string strN, stre;

		file.open(pubKeyFilename.c_str());  // opens file and reads pub key

		file >> strN;
		file >> stre;

		mpz_class N(strN);
		mpz_class e(stre);

		pubKey[0] = N;
		pubKey[1] = e;

}


	mpz_class RSA::encrypt(string message)
	{
		mpz_class c,m(message), p, r;
		ModularArithmetic mod;

		c = mod.modexp(m,pubKey[1],pubKey[0]);  // Raises message to power e the mod N

		return c % pubKey[0];

	}


	mpz_class RSA::decrypt(string data)
	{

		mpz_class r, e, N;
		mpz_class d;
		mpz_class n(data); // converts string to mpz_class

		ModularArithmetic mod;

		r= privKey[1];
		e = pubKey[1];
		N = pubKey[0];

		d=mod.modexp(n,r, N);  // should raise message to the power d mod N
		//d=mod.modexp(n,privKey[1], privKey[0]);


		return d ;
	}

