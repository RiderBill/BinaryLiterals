#include "BinaryLiterals_UnitTestsPCH.h"
#include "BinaryIntClass.h"
//#include "CppUnitTest.h" //Isn't this line redundant? CppUnitTest.h is included in BinLitUnitTestPCH.h
                           // (formerly stdafx.h). The project wizard put it here.

double test = 0.; // Why does this make the following line satisfy intellisense?
#define MakeIntellisenseWorkForTemplate
#ifdef  MakeIntellisenseWorkForTemplate
   typedef  unsigned int IntType;
#else
template<typename IntType>
#endif

std::wstring narroToWideString(const std::string &narrowString)
{  // Modified from http://www.cplusplus.com/forum/general/84768/  string username = "whatever";
   size_t inStrLen = narrowString.length();
   std::wstring wideString(L"");
   wideString.resize(inStrLen);
   for(int i = 0; i < inStrLen; ++i)
   {  wideString += wchar_t( narrowString[i] );
   }
   return wideString;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryLiterals_UnitTests
{		
	TEST_CLASS(UnitTest1)
	{  public:
		
      TEST_METHOD(TestMethod1)
      {
   	   // TODO: Your test code here
           Assert::IsTrue( true
                          , L"dummy method failed\n"
                          , LINE_INFO());
   
      }

      TEST_METHOD(BinaryInt_Tests)
      {  const size_t nTests = 6;
         std::string  inStr  [nTests] = { "0001", "0b0010", "0B0011", "0b0000:0100", "0001:0000",        "0001:0000:0001:0000"};
         std::string  delim  [nTests] = {     "",      ":",      ",",           ":",         ":",                          ":"};
         unsigned int tstVal [nTests] = {     1,        2,        3,             4,           16,  tstVal[4] << 8 +  tstVal[4]};
         BinaryInt    binInt [nTests];

         for(int iTest = 0; iTest<nTests; ++iTest)
         {  std::string tempStr;
            tempStr =  std::string("inStr           = ") + inStr          [iTest] + "\n"
                     +             "delim           = "  + delim          [iTest] + "\n"
                     +             "nBitSize        = " 
                     +             "binInt.toString = "
                     +             "tstVal          = "  + std::to_string(tstVal[iTest]           ) + "\n"
                     +             "binInt value    = "  + std::to_string(binInt[iTest].toValue()) + "\n";
         
            binInt[iTest] = BinaryInt(inStr[iTest], delim[iTest]);
            Assert::IsTrue(  ( (unsigned int)binInt[iTest] == tstVal[iTest])
                            , narroToWideString( std::string("BinaryInt failed.\n" + tempStr)).c_str()
                            , LINE_INFO()
                          );
   
         } // End of for(iTest)

	   } // End of TEST_METHOD(BinaryInt_Tests)
   }; // End of TEST_CLASS(UnitTest1) 
} // End of namespace BinaryLiterals_UnitTests