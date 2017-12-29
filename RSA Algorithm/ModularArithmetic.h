#ifndef MODULARARITHMETIC_H
#define MODULARARITHMETIC_H

#include <gmpxx.h>

class ModularArithmetic {
   public:
      static mpz_class modadd(mpz_class& a, mpz_class& b, mpz_class& N);
      static mpz_class modmult(mpz_class& a, mpz_class& b, mpz_class& N);
      static mpz_class moddiv(mpz_class& a, mpz_class& b, mpz_class& N);
      static mpz_class modexp(mpz_class& a, mpz_class& b, mpz_class& N);
      static bool isPrime(mpz_class& N, int k);
      static mpz_class genPrime(int n);

};

#endif
