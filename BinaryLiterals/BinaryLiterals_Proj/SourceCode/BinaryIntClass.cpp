#include "StdAfx.h"
#include "BinaryIntClass.h"


// Constructors
   //blic:
BinaryInt::BinaryInt(IntType            val    , const std::string &dlm) : value(val)             , delim(*(dlm.c_str())) {}
BinaryInt::BinaryInt(const std::string &strIn  , const std::string &dlm) : value(strToVal(strIn)) , delim(*(dlm.c_str())) {}
                                                                                                                                
// The following two constructors are not required because the compiler automatically converts the char strings                 
// to std::strings???                                                                                                           
//BinaryInt::BinaryInt(IntType            val = 0, const char       dlm = ':') : value(val)             , delim(dlm)            {}
//BinaryInt::BinaryInt(const char const  *cStrIn , const char       dlm = ':') : value(strToVal(cStrIn)), delim(dlm)            {}

// Use implict Copy constructor and assignment operator.
// I will neet to explicitely define them if I add a pointer field variable.
// I'm not sure about adding a std::string field.
// BinaryInt(            BinaryInt<IntType>); // Use implict Copy constructor.
// BinaryInt & operator=(BinaryInt<IntType>); // Use implict assignment operator.

// operator overloads
// public:
            BinaryInt::operator IntType(           ) { return this->toValue()                ; }
BinaryInt & BinaryInt::operator=(std::string newStr) { value = strToVal(newStr); return *this; }
BinaryInt & BinaryInt::operator=(IntType     newVal) { this->value = newVal    ; return *this; }

BinaryInt   BinaryInt::operator+ (IntType    val2) { return BinaryInt(this->value +    val2 ); }
BinaryInt   BinaryInt::operator- (IntType    val2) { return BinaryInt(this->value -    val2 ); }
BinaryInt   BinaryInt::operator* (IntType    val2) { return BinaryInt(this->value *    val2 ); }
BinaryInt   BinaryInt::operator/ (IntType    val2) { return BinaryInt(this->value /    val2 ); }
BinaryInt   BinaryInt::operator% (IntType    val2) { return BinaryInt(this->value %    val2 ); }
BinaryInt   BinaryInt::operator| (IntType    val2) { return BinaryInt(this->value |    val2 ); }
BinaryInt   BinaryInt::operator& (IntType    val2) { return BinaryInt(this->value &    val2 ); }
BinaryInt   BinaryInt::operator^ (IntType    val2) { return BinaryInt(this->value ^    val2 ); }
BinaryInt   BinaryInt::operator+ (BinaryInt &bs  ) { return BinaryInt(this->value + bs.value); }
BinaryInt   BinaryInt::operator- (BinaryInt &bs  ) { return BinaryInt(this->value - bs.value); }
BinaryInt   BinaryInt::operator* (BinaryInt &bs  ) { return BinaryInt(this->value * bs.value); }
BinaryInt   BinaryInt::operator/ (BinaryInt &bs  ) { return BinaryInt(this->value / bs.value); }
BinaryInt   BinaryInt::operator% (BinaryInt &bs  ) { return BinaryInt(this->value % bs.value); }
BinaryInt   BinaryInt::operator| (BinaryInt &bs  ) { return BinaryInt(this->value | bs.value); }
BinaryInt   BinaryInt::operator& (BinaryInt &bs  ) { return BinaryInt(this->value & bs.value); }
BinaryInt   BinaryInt::operator^ (BinaryInt &bs  ) { return BinaryInt(this->value ^ bs.value); }

BinaryInt & BinaryInt::operator+=(IntType    val2) { this->value +=    val2 ; return *this;  }
BinaryInt & BinaryInt::operator-=(IntType    val2) { this->value -=    val2 ; return *this;  }
BinaryInt & BinaryInt::operator*=(IntType    val2) { this->value *=    val2 ; return *this;  }
BinaryInt & BinaryInt::operator/=(IntType    val2) { this->value /=    val2 ; return *this;  }
BinaryInt & BinaryInt::operator%=(IntType    val2) { this->value %=    val2 ; return *this;  }
BinaryInt & BinaryInt::operator|=(IntType    val2) { this->value |=    val2 ; return *this;  }
BinaryInt & BinaryInt::operator&=(IntType    val2) { this->value &=    val2 ; return *this;  }
BinaryInt & BinaryInt::operator^=(IntType    val2) { this->value ^=    val2 ; return *this;  }
BinaryInt & BinaryInt::operator+=(BinaryInt &bs  ) { this->value += bs.value; return *this;  }
BinaryInt & BinaryInt::operator-=(BinaryInt &bs  ) { this->value -= bs.value; return *this;  }
BinaryInt & BinaryInt::operator*=(BinaryInt &bs  ) { this->value *= bs.value; return *this;  }
BinaryInt & BinaryInt::operator/=(BinaryInt &bs  ) { this->value /= bs.value; return *this;  }
BinaryInt & BinaryInt::operator%=(BinaryInt &bs  ) { this->value %= bs.value; return *this;  }
BinaryInt & BinaryInt::operator|=(BinaryInt &bs  ) { this->value |= bs.value; return *this;  }
BinaryInt & BinaryInt::operator&=(BinaryInt &bs  ) { this->value &= bs.value; return *this;  }
BinaryInt & BinaryInt::operator^=(BinaryInt &bs  ) { this->value ^= bs.value; return *this;  }

std::istream&  BinaryInt::operator >>(std::istream &istrm)
//Is this even useful?
{  std::string tmpString;
   istrm >> tmpString;
   value = (*this).strToVal(tmpString);
   return istrm;
}

//friend function
std::istream&  operator >>(std::istream &istrm, BinaryInt &bs)
{  std::string tmpString;
   istrm >> tmpString;
   bs.value = bs.strToVal(tmpString);
   return istrm;
}

//friend function
std::ostream& operator<< (std::ostream &ostrm, BinaryInt &bs)
{  return (ostrm << bs.toString() );
}


IntType BinaryInt::nBits   () { return this->nBitSize ; }
IntType BinaryInt::toValue () { return this->value    ; }
char    BinaryInt::getDelim() { return this-> delim   ; }
char    BinaryInt::setDelim(const char newDelim)
{  // Any printable character except '0', '1', 'b', and 'B'
   // is a valid delimiter.
   // If an newDelim is invalid, this->delim is not changed,
   // except for the special case of newDelim = 0, which is
   // interpreted as no delimiter.
   if (    (newDelim != '0')  && (newDelim != '1')
        && (newDelim != 'b')  && (newDelim != 'B')
        && (isprint(newDelim) || (newDelim ==  0 ) ) )
        delim = newDelim;
   return delim;
}

std::string BinaryInt::toString(  const char delm
                                , size_t nDigits)
{  // Return std::string representation of *this.
   std::string strngOut("0b");
   size_t nDigitsReqd;
   // Default delimiter is the this->delim.
   char delim_;
   if (delm == 1) delim_ = this->delim;
   // Find the minimum number of digits required to display the value.
   for(size_t iBit=nBitSize-1; iBit>=0; --iBit)
   {  IntType mask = ((IntType) 1) << iBit;
      if ((value & mask) == 1)
      {  nDigitsReqd = iBit+1;
         break;
      }
   }
   nDigits = (nDigits > nDigitsReqd) ? nDigits : nDigitsReqd;
   nDigits = (nDigits < nBitSize   ) ? nDigits : nBitSize   ;
   nDigits = (nDigits > 1          ) ? nDigits : 1          ;

   // Make the string.
   for(size_t iBit=nDigits-1; iBit>=0; --iBit)
   {  IntType mask = ((IntType) 1) << iBit;
      if ((value & mask) == 0) strngOut += '0';
      else                     strngOut += '1';
      // Insert delim chars for readability.
      if (    (iBit % 4 == 0        )
           && (iBit     !=         0)
           && (iBit     != nDigits-1)
           && (delim_   !=         0) ) strngOut += delm;
   }
   return strngOut;
} // End of BinaryInt::toString(const char delm, int nDigits)

// private:
IntType BinaryInt::strToVal(const char      *cStrIn)
{  std::string strnIn(cStrIn);
   return strToVal   (strnIn);
}

IntType BinaryInt::strToVal(const std::string &strIn)
{  // Strip prefix and delimiter characters. 
   // The validateNumberString() function should catch invalidly 
   // formated strings, so it shouldn't be necessary to use the
   // try/catch block, but I'm going to anyway, because stripping
   // functions can issue an exception if the string format is invalid,
   try
   {  if ( !validateNumberString(strIn) ) throw new std::exception;
      std::string strNoPrefix        = stripPrefix    (strIn     );  
      std::string strNoPrefixNoDelim = stripDelimiters(strNoPrefix);
      // Now the string consists of the digits 0 and 1 only,
      // and contains no more than nBitSize characters.
      size_t nBits = strIn.length();
      IntType val = 0;
      for (size_t ibit = 0; ibit < nBits; ++nBits)
      {  val <<= 1;
         if (strIn.at(ibit) == '1') val += 1;
      }
      return val;
   }
   catch (std::exception e)
   {  // Issue error statement, then exit code "gracefully."
      std::cerr << std::string("Invalid BinaryInt value string: \n") + strIn;
      throw e; 
   }
} // End of BinaryInt::strToVal(const std::string &inStr)

bool BinaryInt::validateNumberString(const std::string &strIn)
{  // Make sure string represents a binary number.
   // Optional prefix must be "0B" or "0b"
   // All digits following the optional prefix must be '0' or '1'
   bool validPrefix      ; // Validates just the optional first two characters
   bool validBinaryString; // Validates characters following the optional
                           // "0b" or "0B" prefix.
   validPrefix        = validatePrefix(strIn);
   validBinaryString  = validateBinaryString(strIn);
   return validPrefix & validBinaryString;
}

bool BinaryInt::validatePrefix(const std::string &strIn)
{  ////////////////////////////////////////////////////////////////////////////
   // Validates just the optional first two characters.
   // Return values:
   //    true:  - strIn begins with "0B" or "0b" (valid prefix).
   //           - strIn begins with "00", "01", "10", or "11" (no prefix)
   //           - strIn = "0" or "1" (no prefix, single digit)
   //    false: - strIn begins with something other than the above.
   //           - strIn length is zero.
   //
   // Note: A number string with no prefix is valid.
   ////////////////////////////////////////////////////////////////////////////
   char char1, char2;
   if ( strIn.length() == 0 )                                return false;

   char1 = (char)toupper((int) strIn[0]); // For convenience
   if ( strIn.length() == 1)
   {  if ( (char1 == '0') || (char1 == '1') )                return true;
      else                                                   return false;
   }

   // strIn.length() >= 2   
   char2 = (char)toupper((int) strIn[1]); // For convenience
   if      ( (char1 == '0') && (    (char2 == '0')
                                 || (char2 == '1')
                                 || (char2 == 'B') ) )       return true;
   else if ( (char1 == '1') && (    (char2 == '0')            
                                 || (char2 == '1') ) )       return true;
   else                                                      return false;
} // End of validatePrefix()

bool BinaryInt::validateBinaryString(const std::string &strIn)
{  // Validate just the binary digits, including optional delimiter characters.
   bool    valid = true;
   size_t  ibit  = 0  ;
   for(size_t ichar=0; ichar<strIn.length()-1; ++ichar)
   {  if( (strIn[ibit] == '0' ) || (strIn[ibit] == '1' ) )
      {  ++ibit;
         continue;
      }
      if (  ( strIn[ibit] == delim            ) 
          &&( ibit % 4 == 0                   ) 
          &&( ibit     != 0                   ) 
          &&( (ibit    != strIn.length() - 1  ) ) )
      {  continue;
      }
      valid = false;
      break;
   } // End of for(ichar)
   if (ibit > nBitSize) valid = false;

   return valid;
}  // End of BinaryInt::validateNumberString(const std::string strIn)

std::string BinaryInt::stripPrefix(const std::string &strIn)
{  // Strip optional 0b or 0B prefix.
   // Assume string has already been validated.
   if ( (strIn.length() < 2) || strIn[1] != 'b' && strIn[1] != 'B')
      return strIn;
   else
      return strIn.substr(2, std::string::npos);
} // End of BinaryInt::stripPrefix(const std::string &strIn)

std::string BinaryInt::stripDelimiters(const std::string &strIn)
{  // If present, delimiter characters should only occur between groups of
   // four bits, counting from right to left.
   // If they occur anywhere else, the string is badly formatted and an
   // exception will be thrown.
   // ******** This function throughs an exception of type std::exception if
   // ******** the string is determined to be invalid.
   std::string strOut("");
   strOut.resize(nBitSize); // I think this is worthwhile; the string should
                            // a fixed size.
   // Strip leading "0b" or "0B" prefix first.
   std::string strNoPrefix = stripPrefix(strIn);
   size_t nChars           = strNoPrefix.size();
   size_t nBits = 0;
   for (size_t iChar = nChars-1; iChar >= 0; --iChar)
   {  if( (strNoPrefix[iChar] == '0') || (strNoPrefix[iChar] == '1') )
      {  strOut = strNoPrefix.at(iChar) + strOut;
         ++nBits;
         continue;
      }
      else
      {  // Not '0' or '1'. Check for invalid delimiter character.
         if (  (  strNoPrefix[iChar] != delim  && strNoPrefix[iChar] != ' ') // blank is a default delimiter
             ||( (nBits+1) % 4 == 0) )
         {  throw new std::exception();
         }
      }
   }
   if (strOut.length() > nBitSize) throw new std::exception();
   return strOut;
} // End of stripDelimiters()

std::string BinaryInt::stripToBinaryString(const std::string &strIn)
{  // Combine into single statement for efficiency ();
   try
   {  return stripDelimiters(stripPrefix(strIn));
   }
   catch(std::exception &e)
   {  // Issue error statement, then exit code "gracefully."
      std::cerr << std::string("Invalid BinaryInt value string: \n") + strIn;
      throw e; 
   }
}