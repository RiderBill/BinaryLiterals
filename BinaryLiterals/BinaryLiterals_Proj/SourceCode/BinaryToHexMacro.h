// BinaryToHex.h

#pragma once
#ifndef BINARYTOHEX_H
   #define BINARYTOHEX_H

   #define U32 unsigned int32
   #define B2HEX_0000  0x0
   #define B2HEX_0001  0x1
   #define B2HEX_0010  0x2
   #define B2HEX_0011  0x3
   #define B2HEX_0100  0x4
   #define B2HEX_0101  0x5
   #define B2HEX_0110  0x6
   #define B2HEX_0111  0x7
   #define B2HEX_1000  0x8
   #define B2HEX_1001  0x9
   #define B2HEX_1010  0xA
   #define B2HEX_1011  0xB
   #define B2HEX_1100  0xC
   #define B2HEX_1101  0xD
   #define B2HEX_1110  0xE
   #define B2HEX_1111  0xF

   #define BINARY_TO_HEX(x7, x6, x5, x4, x3, x2, x1, x0)  \
                               ( B2HEX_ ## x0       ) +   \
                               ( B2HEX_ ## x1 <<  4 ) +   \
                               ( B2HEX_ ## x2 <<  8 ) +   \
                               ( B2HEX_ ## x3 << 12 ) +   \
                               ( B2HEX_ ## x4 << 16 ) +   \
                               ( B2HEX_ ## x5 << 20 ) +   \
                               ( B2HEX_ ## x6 << 24 ) +   \
                               ( B2HEX_ ## x7 << 28 )
   // Can't put parentheses around the arguments???
   //#define BINARY_TO_HEX(x7, x6, x5, x4, x3, x2, x1, x0)  \
   //                            ( B2HEX_ ## (x0)       ) + \
   //                            ( B2HEX_ ## (x1) <<  4 ) + \
   //                            ( B2HEX_ ## (x2) <<  8 ) + \
   //                            ( B2HEX_ ## (x3) << 12 ) + \
   //                            ( B2HEX_ ## (x4) << 16 ) + \
   //                            ( B2HEX_ ## (x5) << 20 ) + \
   //                            ( B2HEX_ ## (x6) << 24 ) + \
   //                            ( B2HEX_ ## (x7) << 28 )

#endif // BINARYTOHEX_H