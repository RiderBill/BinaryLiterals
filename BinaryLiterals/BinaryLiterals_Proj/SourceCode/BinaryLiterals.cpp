#include "StdAfx.h"
#include "BinaryToHexMacro.h"
#include "BinaryIntClass.h"

std::wstring narroToWideString(const std::string &narrowString);

BinaryInt intBinary00("                                          " );

BinaryInt intBinary11("                      1                   " );
BinaryInt intBinary12("                      1" ,             ","  );
BinaryInt intBinary13("                      1" , std::string(", "));

BinaryInt intBinary21(            "0110:0111"                    );
BinaryInt intBinary22(            "0110:0111" ,             ", " );
BinaryInt intBinary23(            "0110:0111" , std::string(", "));

BinaryInt intBinary31(std::string("0110:0111")                   );
BinaryInt intBinary32(std::string("0110:0111"),             ", " );
BinaryInt intBinary33(std::string("0110:0111"), std::string(", "));

template<typename T> std::string toBinStr(T val)
{  std::stringstream ss;
   size_t nBits = 8*sizeof(T);
   for(int iBit=nBits; iBit>0; --iBit)
   {  if ( (iBit != nBits) && (iBit % 4 == 0) ) ss << ", ";
      ss <<  (int) ( (val >> (iBit-1 ) ) & 1 );
   }
   return ss.str();
} // End of template<typeName T> std::string h2BS(T val)

int main(int argc, char *argv[])
{
   unsigned int test  = B2HEX_0010;
   unsigned int test0 = BINARY_TO_HEX(0000,0000,0000,0000,0000,0000,0000,0000); // 0
   unsigned int test1 = BINARY_TO_HEX(0000,0000,0000,0000,0000,0000,0000,0001); // 1
   unsigned int test2 = BINARY_TO_HEX(0000,0000,0000,0000,0000,0000,0000,0010); // 2
   unsigned int test3 = BINARY_TO_HEX(0000,0000,0000,0000,0000,0000,0000,1011); // 11
   unsigned int test4 = BINARY_TO_HEX(0000,0000,0000,0000,1000,0000,1000,0100); // 32768 + 128 + 4 = 32900
   unsigned int test5 = BINARY_TO_HEX(1111,1111,1111,1111,1111,1111,1111,1111); // 2^32 - 1 = 4 billion and change.

// std::ofstream ofs("BinaryLiteralTest.txt", std::ios_base::out);
   std::ostream &ofs = std::cout;
   ofs << "b2HexTest:\n";
   ofs <<  "test  = "; ofs.width(10); ofs << test  << "\n"
       <<  "      = " << BinaryInt(test) << "\n";
   ofs << "binaryTest0 = "; ofs.width(10); ofs << test0 << " = " << BinaryInt(test0) << "\n";
   ofs << "binaryTest1 = "; ofs.width(10); ofs << test1 << " = " << BinaryInt(test1) << "\n";
   ofs << "binaryTest2 = "; ofs.width(10); ofs << test2 << " = " << BinaryInt(test2) << "\n";
   ofs << "binaryTest3 = "; ofs.width(10); ofs << test3 << " = " << BinaryInt(test3) << "\n";
   ofs << "binaryTest4 = "; ofs.width(10); ofs << test4 << " = " << BinaryInt(test4) << "\n";
   ofs << "binaryTest5 = "; ofs.width(10); ofs << test5 << " = " << BinaryInt(test5) << "\n";

   ofs << "b2HexTest   = "; ofs.width(10); ofs << test  << " = " << toBinStr(test )     << "\n";
   ofs << "binaryTest0 = "; ofs.width(10); ofs << test0 << " = " << toBinStr(test0)     << "\n";
   ofs << "binaryTest1 = "; ofs.width(10); ofs << test1 << " = " << toBinStr(test1)     << "\n";
   ofs << "binaryTest2 = "; ofs.width(10); ofs << test2 << " = " << toBinStr(test2)     << "\n";
   ofs << "binaryTest3 = "; ofs.width(10); ofs << test3 << " = " << toBinStr(test3)     << "\n";
   ofs << "binaryTest4 = "; ofs.width(10); ofs << test4 << " = " << toBinStr(test4)     << "\n";
   ofs << "binaryTest5 = "; ofs.width(10); ofs << test5 << " = " << toBinStr(test5)     << "\n";

   return 0;
}

std::wstring narroToWideString(const std::string &narrowString)
{  // Modified from http://www.cplusplus.com/forum/general/84768/  string username = "whatever";
   int inStrLen = narrowString.length();
   std::wstring wideString(L"");
   wideString.resize(inStrLen);
   for(int i = 0; i < inStrLen; ++i)
   {  wideString += wchar_t( narrowString[i] );
   }
   return wideString;
}


	