// BinaryIntClass.h
#pragma once
#ifndef  BINARY_INT_CLASS_H
#define BINARY_INT_CLASS_H
#define MakeIntellisenseWorkForTemplate
#ifdef  MakeIntellisenseWorkForTemplate
   typedef  unsigned int IntType;
#else
template<typename IntType>
#endif
//BinaryInt<IntType> intBinary();
class BinaryInt
{  
   // Note that a string representation is not maintained as a field variable.
   // I may reconsider that.
   // For now, the object state consists of two field variables: value and delim.
   // (nBitSize is a constant for each IntType.
   private:
   IntType value   ; // Integer value of BinaryInt
   char    delim   ; // Delimiter string to use between sets of four bit characters
                     // for readability
   const size_t nBitSize = 8*sizeof(IntType); // Number of bits in IntType (for convenience).

   // Constructors
   public:
   BinaryInt(IntType            val = 0, const std::string &dlm = ":");
   BinaryInt(const std::string &strIn  , const std::string &dlm = ":");

   // The following two constructors are not required because the compiler automatically converts the char strings
   // to std::strings???
   //BinaryInt(IntType            val = 0, const char         dlm = ':');
   //BinaryInt(const char const  *cStrIn , const char         dlm = ':');

// public:
// Use implict Copy constructor and assignment operator.
// I will neet to explicitely define them if I add a pointer field variable.
// I'm not sure about adding a std::string field.
// BinaryInt(            BinaryInt<IntType>); // Use implict Copy constructor.
// BinaryInt & operator=(BinaryInt<IntType>); // Use implict assignment operator.

   // operator overloads
   public:
               operator IntType(           );
   BinaryInt & operator=(std::string newStr);
   BinaryInt & operator=(IntType     newVal);

   BinaryInt   operator+ (IntType     val2 );
   BinaryInt   operator- (IntType     val2 );
   BinaryInt   operator* (IntType     val2 );
   BinaryInt   operator/ (IntType     val2 );
   BinaryInt   operator% (IntType     val2 );
   BinaryInt   operator| (IntType     val2 );
   BinaryInt   operator& (IntType     val2 );
   BinaryInt   operator^ (IntType     val2 );
   BinaryInt   operator+ (BinaryInt  &bs   );
   BinaryInt   operator- (BinaryInt  &bs   );
   BinaryInt   operator* (BinaryInt  &bs   );
   BinaryInt   operator/ (BinaryInt  &bs   );
   BinaryInt   operator% (BinaryInt  &bs   );
   BinaryInt   operator| (BinaryInt  &bs   );
   BinaryInt   operator& (BinaryInt  &bs   );
   BinaryInt   operator^ (BinaryInt  &bs   );

   BinaryInt & operator+=(IntType    val2);
   BinaryInt & operator-=(IntType    val2);
   BinaryInt & operator*=(IntType    val2);
   BinaryInt & operator/=(IntType    val2);
   BinaryInt & operator%=(IntType    val2);
   BinaryInt & operator|=(IntType    val2);
   BinaryInt & operator&=(IntType    val2);
   BinaryInt & operator^=(IntType    val2);
   BinaryInt & operator+=(BinaryInt &bs  );
   BinaryInt & operator-=(BinaryInt &bs  );
   BinaryInt & operator*=(BinaryInt &bs  );
   BinaryInt & operator/=(BinaryInt &bs  );
   BinaryInt & operator%=(BinaryInt &bs  );
   BinaryInt & operator|=(BinaryInt &bs  );
   BinaryInt & operator&=(BinaryInt &bs  );
   BinaryInt & operator^=(BinaryInt &bs  );

   bool        operator||(IntType     newVal);
   bool        operator||(BinaryInt  &bs    );
   bool        operator&&(IntType     newVal);
   bool        operator&&(BinaryInt  &bs    );

   std::istream&        operator >>(std::istream &istrm);
   friend std::istream& operator >>(std::istream &istrm, BinaryInt &bs);
   friend std::ostream& operator<< (std::ostream &ostrm, BinaryInt &bs);

   public:
   IntType     nBits   ();
   IntType     toValue ();
   char        getDelim();
   char        setDelim(const char newDelim = ':');
   std::string toString(  const char = 1
                        , size_t nDigits = 8*sizeof(IntType) );
   private:
   IntType     strToVal(const std::string &strnIn);
   IntType     strToVal(const char* const  cStrIn);

   bool        validateNumberString(const std::string &strIn);
   bool        validatePrefix      (const std::string &strIn);
   bool        validateBinaryString(const std::string &strIn);
   std::string stripPrefix         (const std::string &strIn);
   std::string stripDelimiters     (const std::string &strIn);
   std::string stripToBinaryString (const std::string &strIn);
   // Delimiter characters are not required, but if present, should only occur between groups
   // of four bits, counting from right to left.
   // If they occur anywhere else, the string is badly formatted and an exception will be thrown.
   // Strip leading "0b" or "0B" prefix first.



}; // End of template <IntType T> class BinaryInt

#endif  BINARY_INT_CLASS_H
