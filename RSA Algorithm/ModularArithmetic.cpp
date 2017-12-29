#include "ModularArithmetic.h"
#include <iostream>
#include <math.h>

					//Alessandro Rizzi Lab 1
using namespace std;

   mpz_class ModularArithmetic::modadd (mpz_class& a,mpz_class&  b, mpz_class&  N)
        {
            mpz_class c, d, e; // Takes modulo of the two numbers to be added then adds them and takes modulo
            c = a % N;
            d = b % N;
            return e = (a + b) % N;
        }

    mpz_class ModularArithmetic::modmult(mpz_class& a,mpz_class& b,mpz_class& N)
        {

           mpz_class c;		// Takes modulo then multiplies then modulo again
            a = a % N;
            b = b % N;
            return c = (a * b) % N;
        }

    mpz_class ModularArithmetic::moddiv(mpz_class& a,mpz_class&  b,mpz_class&  N)
        {
            mpz_class c;
            mpz_t p;

            mpz_class inv;



            b.get_mpz_t();

           if (mpz_invert(p,b.get_mpz_t(),N.get_mpz_t()) == 0)
	{
                cout << "not invertible" << endl;
	}

	    mpz_invert(p,b.get_mpz_t(),N.get_mpz_t());
            inv = mpz_class(p);


            return (a*inv)%N;





        }

    mpz_class ModularArithmetic::modexp(mpz_class& x, mpz_class&  y, mpz_class&  N)
        {
            mpz_class c,d, e;
            if (y==0)
                {
                    return 1;
                }
	d=y/2;					// Recursive function from class;

            c=modexp(x, d , N);

            if(y % 2 == 0)
                {
                    return  (modmult(c,c,N));
                }
            else
               {
                    return (x * modmult(c,c,N)) % N ;
                }

	}

  bool ModularArithmetic::isPrime(mpz_class& N, int k)
{
	mpz_class a, b, rand;
	gmp_randclass r1(gmp_randinit_default);
	bool isprime = false;

	for ( int i=0; i<k; i++)
	{
	r1.seed(time(NULL));
	// sleep(1/10);
		rand = r1.get_z_range(N-2);	// function works from 0 to n-1 so the extra addition takes advantage of this
		rand = rand + 2;
		// generate for 1<= a <= p-1         prob of false positive 1/2^k

		b = N-1;


		if (modexp(rand,b, N) == 1)

		{

			isprime = true;

		}

		else
		{

			return false;

		}
	}

	return true;
}

      mpz_class ModularArithmetic::genPrime(int n)
	{
	mpz_class rand;
	gmp_randclass r2 (gmp_randinit_default);
	r2.seed(time(NULL));
	rand = r2.get_z_bits(n);		//Generates random numbers
	label:
		while (rand < (1<<(n-1)))		// loops until have a number above the floor. bitwise shift to achieve desired exponentiation
		{
	 		rand = r2.get_z_bits(n);

		}

		 if (isPrime (rand, 130) == false)  // Checks if prime
		{
			rand = r2.get_z_bits(n);
			goto label;
		}




	return rand;

}
		// floor 2^(n-1)  ceiling (2^n) -1

//rizza15


    //dtor
