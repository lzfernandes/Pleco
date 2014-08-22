
/*
 * Copyright (c) 2014, University of Waterloo
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the University of Waterloo nor the
 *   names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior
 *   written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @author Xinxin Fan <fan@openecc.org>
 * @date   May 19, 2014
 */

#include <stdint.h>

typedef uint8_t uint8;
typedef uint32_t uint32;
typedef int32_t sint32;
typedef uint64_t uint64;

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//p = 0xD091BB5C 22AE9EF6 E7E1FAEE D5C31F79 2082352C F807B7DF E9D30005 3895AFE1 A1E24BBA 4EE4092B 18F86863 8C16A625 474BA8C4 3039CD1A 8C006D5F FE2D7810 
//      F51F2AE7 FF1816E4 F702EF59 F7BADAFA 285954A1 B9D09511 F878C4B3 FB2A0137 F508E4AA 1C1FE652 7C419418 CC50AA59 CCDF2E5C 4C0A1F3B 2452A9DC 01397D8D 
//      6BF88C31 1CCA797A EA6DA4AE A3C78807 CACE1969 E0E0D4AD F5A14BAB 80F00988 A7DE9F4C CC450CBA 0924668F 5C7DC380 D96089C5 3640AC4C EF1A2E6D AE6D97B7
//q = 0xADC1965B 6613BA46 C1FB41C2 BD9B0ECD BE3DEDFC 7989C8EE 6468FD6E 6C0DF032 A7CD6634 2C826D8B 2BD2E412 4D4A2DBE B4BF6FA7 CC1A8959 08263282 51097330 
//      46E46CB0 DF577EC2 0BD1E364 262C5564 18DDA0C9 FE7B45D9 D2CE21C9 D268409A B1E049E1 200BFA47 512D6E73 C3851EEE F341C081 7D973E48 08D17554 A9E20D28 
//      70518CE6 203AC303 61ADD0AB 35D0430C C3F8E892 0D1C8509 CB92388E 095436BF 2FD6E208 68A29AF9 7D61330B 753EC6FC 7211EFEA 7CD15133 A574C4FF CB41FA1F
uint32 p[48] = {0xAE6D97B7,0xEF1A2E6D,0x3640AC4C,0xD96089C5,0x5C7DC380,0x0924668F,0xCC450CBA,0xA7DE9F4C,
	            0x80F00988,0xF5A14BAB,0xE0E0D4AD,0xCACE1969,0xA3C78807,0xEA6DA4AE,0x1CCA797A,0x6BF88C31,
	            0x01397D8D,0x2452A9DC,0x4C0A1F3B,0xCCDF2E5C,0xCC50AA59,0x7C419418,0x1C1FE652,0xF508E4AA,
	            0xFB2A0137,0xF878C4B3,0xB9D09511,0x285954A1,0xF7BADAFA,0xF702EF59,0xFF1816E4,0xF51F2AE7,
                0xFE2D7810,0x8C006D5F,0x3039CD1A,0x474BA8C4,0x8C16A625,0x18F86863,0x4EE4092B,0xA1E24BBA,
                0x3895AFE1,0xE9D30005,0xF807B7DF,0x2082352C,0xD5C31F79,0xE7E1FAEE,0x22AE9EF6,0xD091BB5C};	            
uint32 q[48] = {0xCB41FA1F,0xA574C4FF,0x7CD15133,0x7211EFEA,0x753EC6FC,0x7D61330B,0x68A29AF9,0x2FD6E208,
	            0x095436BF,0xCB92388E,0x0D1C8509,0xC3F8E892,0x35D0430C,0x61ADD0AB,0x203AC303,0x70518CE6,
	            0xA9E20D28,0x08D17554,0x7D973E48,0xF341C081,0xC3851EEE,0x512D6E73,0x200BFA47,0xB1E049E1,
	            0xD268409A,0xD2CE21C9,0xFE7B45D9,0x18DDA0C9,0x262C5564,0x0BD1E364,0xDF577EC2,0x46E46CB0,
	            0x51097330,0x08263282,0xCC1A8959,0xB4BF6FA7,0x4D4A2DBE,0x2BD2E412,0x2C826D8B,0xA7CD6634,
	            0x6C0DF032,0x6468FD6E,0x7989C8EE,0xBE3DEDFC,0xBD9B0ECD,0xC1FB41C2,0x6613BA46,0xADC1965B};

//n = p * q
//= 0x8D9033FB 5EA5E060 7DBC9AFB C5CE3791 F504E603 D5409F6A D34D0529 B3A1CAC0 53A06364 37175555 1C88931F 75E8AB3E 4E56999B DBE68166 8FFCDD09 A7E905F7 
//    0BFCBCE9 44569A9A 4162AE90 240CE865 AE091B04 37523E3C 8EDB3206 A87BDEC6 00321C2D D3BD6AF0 9B591D9E B4672BCF 4A1E4EEE 7C8342F3 26C5B755 73145F73 
//	  A1DB9792 B9468DEB 2C7F5F5C B72C2235 3E67B12E 97E94165 CF828843 10BF5D57 5AA08DA0 0EB68D1F 2511A320 B10AD688 5087DBE1 5CAC6CB7 DC16FB8B A3C03BA7 
//	  E7D36915 3FB9EB99 BAA1F2F6 C94222B5 B97A00C7 946CDB7D C6427620 24287A43 4DFF6DD7 96564E04 DAA7AD1D 9D495302 F53FE49F D85D7831 E6F86846 AE1FCE82 
//	  6DC33A08 54A89F98 4DFB571E 993C91CB 7A5D6286 C6416771 3ED6154C B17E85C3 BF4B4B6C 4AAAC48E 9652660A 39FDFC00 48EAEBA5 6BE7F450 8F84CD73 8BE3D995 
//	  EE39831B CBD1C63D D96202B5 25FD2C39 61D03936 B085D28D BDC35963 C643909A 003E8E55 B0C0C5DA 1BA7E740 C70365E7 728A0BAB 5A377CFA A1EB2809 C7E51529

uint32 n[96] = {0xC7E51529,0xA1EB2809,0x5A377CFA,0x728A0BAB,0xC70365E7,0x1BA7E740,0xB0C0C5DA,0x003E8E55,
	            0xC643909A,0xBDC35963,0xB085D28D,0x61D03936,0x25FD2C39,0xD96202B5,0xCBD1C63D,0xEE39831B,
	            0x8BE3D995,0x8F84CD73,0x6BE7F450,0x48EAEBA5,0x39FDFC00,0x9652660A,0x4AAAC48E,0xBF4B4B6C,
	            0xB17E85C3,0x3ED6154C,0xC6416771,0x7A5D6286,0x993C91CB,0x4DFB571E,0x54A89F98,0x6DC33A08,
	            0xAE1FCE82,0xE6F86846,0xD85D7831,0xF53FE49F,0x9D495302,0xDAA7AD1D,0x96564E04,0x4DFF6DD7,
	            0x24287A43,0xC6427620,0x946CDB7D,0xB97A00C7,0xC94222B5,0xBAA1F2F6,0x3FB9EB99,0xE7D36915,
	            0xA3C03BA7,0xDC16FB8B,0x5CAC6CB7,0x5087DBE1,0xB10AD688,0x2511A320,0x0EB68D1F,0x5AA08DA0,
	            0x10BF5D57,0xCF828843,0x97E94165,0x3E67B12E,0xB72C2235,0x2C7F5F5C,0xB9468DEB,0xA1DB9792,
	            0x73145F73,0x26C5B755,0x7C8342F3,0x4A1E4EEE,0xB4672BCF,0x9B591D9E,0xD3BD6AF0,0x00321C2D,
	            0xA87BDEC6,0x8EDB3206,0x37523E3C,0xAE091B04,0x240CE865,0x4162AE90,0x44569A9A,0x0BFCBCE9,
	            0xA7E905F7,0x8FFCDD09,0xDBE68166,0x4E56999B,0x75E8AB3E,0x1C88931F,0x37175555,0x53A06364,
	            0xB3A1CAC0,0xD34D0529,0xD5409F6A,0xF504E603,0xC5CE3791,0x7DBC9AFB,0x5EA5E060,0x8D9033FB};

//u = [(2^32)^192/n]
//= 0x1 CEF1E2D5 9920E7AE AE0B4D79 ECBCEBFB 665458A8 6972FD98 5859ED30 0258899D D62AD975 679EDF67 AC6B8ABC FDC04F3E A84C4CC0 58B1FFE1 CC02BB9B D089C91C 
//      FEC4BC71 0C9E47BE 8891FF03 BB5A3810 36D86EE9 DED5EC0B 4D0C57C6 BAB3FE20 12E973D8 07864D3B 8B762DAE DC4FDFC3 96AEB7E4 CB4B0976 BAD337C5 6EE99741 
//      D2521D61 2282921B B03C6FED E9613FFF 83EE6CCB 79696AAC CC6817D6 0B20E5A9 B405B4CF E820C88D C85AD2B1 F4697C4A FFC96AA4 31A73DD2 BC8DAB51 35621DA5 
//      1F7669DB E7C2D703 8D53F2A0 5A463DC3 09295211 13DEFB7D 06E5A1E8 11388E13 B39AB9E3 4CC755E7 63714E61 DAEDEE97 6055A210 0EDE8BD5 8EA121D5 EAB8FE75 
//      F6383590 A93124A1 D401FE44 6858EB72 A0DA6983 5EAAE5F6 26C30877 031D9EC9 86F32EC2 B487883E 073227CB 1C89939C C30A45BB A3FC4A66 EA8261D4 4DD6FCCE 
//      AFBAD6A2 EAA5E075 0A23498A 26CDC646 D75231BC 58B4D742 128061DD 3321A5FC FE4BFD10 22EEE14B 6C3872CF F882F3B7 7869F811 25003C1D 9E32FEAF 4E9ABFCA 
uint32 un[97] = {0x4E9ABFCA,0x9E32FEAF,0x25003C1D,0x7869F811,0xF882F3B7,0x6C3872CF,0x22EEE14B,0xFE4BFD10,
	             0x3321A5FC,0x128061DD,0x58B4D742,0xD75231BC,0x26CDC646,0x0A23498A,0xEAA5E075,0xAFBAD6A2,
	             0x4DD6FCCE,0xEA8261D4,0xA3FC4A66,0xC30A45BB,0x1C89939C,0x073227CB,0xB487883E,0x86F32EC2,
	             0x031D9EC9,0x26C30877,0x5EAAE5F6,0xA0DA6983,0x6858EB72,0xD401FE44,0xA93124A1,0xF6383590,
	             0xEAB8FE75,0x8EA121D5,0x0EDE8BD5,0x6055A210,0xDAEDEE97,0x63714E61,0x4CC755E7,0xB39AB9E3,
	             0x11388E13,0x06E5A1E8,0x13DEFB7D,0x09295211,0x5A463DC3,0x8D53F2A0,0xE7C2D703,0x1F7669DB,
	             0x35621DA5,0xBC8DAB51,0x31A73DD2,0xFFC96AA4,0xF4697C4A,0xC85AD2B1,0xE820C88D,0xB405B4CF,
	             0x0B20E5A9,0xCC6817D6,0x79696AAC,0x83EE6CCB,0xE9613FFF,0xB03C6FED,0x2282921B,0xD2521D61,
	             0x6EE99741,0xBAD337C5,0xCB4B0976,0x96AEB7E4,0xDC4FDFC3,0x8B762DAE,0x07864D3B,0x12E973D8,
	             0xBAB3FE20,0x4D0C57C6,0xDED5EC0B,0x36D86EE9,0xBB5A3810,0x8891FF03,0x0C9E47BE,0xFEC4BC71,
	             0xD089C91C,0xCC02BB9B,0x58B1FFE1,0xA84C4CC0,0xFDC04F3E,0xAC6B8ABC,0x679EDF67,0xD62AD975,
	             0x0258899D,0x5859ED30,0x6972FD98,0x665458A8,0xECBCEBFB,0xAE0B4D79,0x9920E7AE,0xCEF1E2D5,0x1};

uint32 sub(uint32 *a, uint32 *b, uint32 *asubb, const uint32 m)
{
	uint32 i, borrow;
	uint64 T;

	borrow = 1; 
	for(i = 0; i < m; i++)
	{
		T = (uint64)*(a + i) + ~*(b + i) + borrow;
		*(asubb + i) = (uint32)T;
		borrow = (uint32)(T >> 32);
	}
	if(borrow == 0) return 1;     
	else return 0;
}

sint32 compare(uint32 *a, uint32 *b, const uint32 m)
{
	uint32 i;

	for(i = m; i != 0; i--)
	{
		if(*(a + i - 1) < *(b + i - 1)) return -1;  
		if(*(a + i - 1) > *(b + i - 1)) return 1;  
	}
	return 0;                                      
}

//Barrett Modular Reduction
//Compute b = c mod m, where len(c) = 2*len(m) 
void modm(uint32 *c, uint32 *m, uint32 *um, uint32 *b, const uint32 num)
{
	uint32 i, j;
	uint64 T1, T2, T3;
	uint32 *r, *s;

	//dynamic array allocation
	r = (uint32 *)malloc((num + 1) * sizeof(uint32));
	s = (uint32 *)malloc((num + 1) * sizeof(uint32));

	T1 = (uint64)c[num - 1] * um[0];
	T1 = T1 >> 32;

	for(i = num; i < 2*num; i++)
	{
		T3 = 0;
		for(j = num - 1; j <= i; j++)
		{
			T2 = (uint64)c[j] * um[i - j];
			T1 += (uint32)T2;
			T3 += (T2 >> 32);
		}
		T1 = (T1 >> 32) + T3;
	}

	for(i = 0; i < num - 1; i++)
	{
		T3 = 0;
		for(j = i + num; j < 2*num; j++)
		{
			T2 = (uint64)c[j] * um[2*num + i - j];
			T1 += (uint32)T2;
			T3 += (T2 >> 32);
		}
		r[i] = (uint32)T1;
		T1 = (T1 >> 32) + T3;
	}

	T2 = (uint64)c[2*num - 1] * um[num];
	T1 += (uint32)T2;
	r[num - 1] = (uint32)T1;
	r[num] = (uint32)(T1 >> 32) + (uint32)(T2 >> 32);

	//s = r * m
	T1 = (uint64)r[0] * m[0];
	s[0] = (uint32)T1;
	T1 = T1 >> 32;

	for(i = 1; i < num + 1; i++)
	{
		T3 = 0;
		for(j = (i < num ? 0 : 1); j <= i; j++)
		{
			T2 = (uint64)r[j] * m[i - j];
			T1 += (uint32)T2;
			T3 += (T2 >> 32);
		}
		s[i] = (uint32)T1;
		T1 = (T1 >> 32) + T3;
	}

	for(i = num - 1; i != 0; i--)  
		r[i] = m[i];
	r[0] = m[0];
	r[num] = 0;

	if(sub(c, s, s, num + 1) == 1)                 
	{
		for(i = num - 1; i != 0; i--)  
			*(b + i) = *(s + i);
		*b = *s;
		return;
	}

	while(compare(s, r, num + 1) != -1)  
		sub(s, r, s, num + 1);
	for(i = num - 1; i != 0; i--)  
		*(b + i) = *(s + i);
	*b = *s;

	free(r);
	free(s);
}

//Compute asq = a^2 mod m
void modmsq(uint32 *a, uint32 *m, uint32 *um, uint32 *asq, const uint32 num)
{
	uint32 i, j, k;
	uint32 *c;
	uint32 R0, R1, R2, carry;
	uint64 T1, T2;

	//dynamic array allocation
	c = (uint32 *)malloc((2*num) * sizeof(uint32));

	R0 = 0; 
	R1 = 0; 
	R2 = 0;

	for(k = 0; k <= 2*(num-1); k++)
	{
		for(i = (k <= (num - 1) ? 0 : (k - (num - 1))); i <= (k >> 1); i++)
		{
			j = k - i;
			T1 = (uint64)(*(a + i)) *(*(a + j));
			if(i != j)
			{
				carry = (uint32)(T1 >> 63);
				T1 = T1 << 1;
				R2 += carry;
			}
			//(carry, R0) = R0 + V
			T2 = (T1 & 0xFFFFFFFF) + R0;
			carry = (uint32)(T2 >> 32);
			R0 = T2 & 0xFFFFFFFF;
			//(carry, R1) = R1 + U + carry
			T2 = (T1 >> 32) + R1 + carry;
			carry = (uint32)(T2 >> 32);
			R1 = T2 & 0xFFFFFFFF;
			//R2 = R2 + carry
			R2 = R2 + carry;
		}
		c[k] = R0;
		R0 = R1;
		R1 = R2;
		R2 = 0;
	}
	c[2*num-1] = R0;

	modm(c, m, um, asq, num);

	free(c);
}

//Compute public key hash function
void rabin_3072(uint8_t *msg, uint8_t *out)
{
	modmsq((uint32*)msg, n, un, (uint32*)out, 96);
}

                	                	
/*
void main()
{
	uint32 i;
	uint32 msg[96] = {0x4DB9A52D,0xC6951B28,0x75600D88,0xEDEC3D2F,0x612197C7,0x14C4A882,0xAB56454F,0xC7BCFC3C,
		              0xD0D63DCD,0xA02889AD,0x580BC7BB,0x5E5501A5,0x62BDECBD,0x2EFA9644,0x500085E0,0xAFD083DB,
					  0xCFD6F924,0x305F5B0C,0x9F997956,0xBEA4300C,0x49AD9663,0x4BDBAE33,0xB7EDA589,0x8C08C64D,
					  0x60E56773,0x736FBC75,0x7E4AAB21,0xA5D2ADEB,0x213D9F32,0xBB522891,0x421FAE11,0xA62C6E93,
					  0xCF239E4D,0x2B42EE31,0xE88F1AFA,0x0B039B90,0x67ACDC26,0x03F17ADB,0x5290106A,0xD239C5CB,
					  0x0D9B6827,0x5A6899BA,0x8D899F74,0x3C1A8943,0x6F6C42E3,0x0F4DB654,0xC1EBC21F,0x9340DED2,
					  0xA6E76B3B,0xF4C53BAB,0xF4772B41,0xF12A3A21,0x7D84661C,0x21C90078,0x39320CA2,0x18B13E7F,
					  0x7E10AD9C,0x6766C940,0x45D3249C,0x3DDF7AE4,0x35D657E1,0x63C5ECB9,0xE09AEBE7,0xC7BE9961,
					  0x29B1FCCC,0x1C77C8A0,0x088449F4,0x5E86F504,0x5805DE29,0xE669EDD5,0xE3420514,0x5674C771,
					  0x8B4742BC,0x7D3FA930,0x3F72F0C3,0x7DA944F1,0x0C4613A1,0xF1DD92D7,0x4D448DF1,0xE718672D,
					  0xD2CDF95B,0x0CB62703,0xFB5234E0,0x6AD203B6,0xD2963CF5,0x3D6D8755,0x8138AC02,0x2F1494B9,
					  0x40C1B904,0x1F91D464,0x0A5C5094,0x3D6B2529,0xC32E0A94,0x13728D90,0x61E09244,0x66DCE437};
	uint32 digest[96] = {0x0};
	uint64 t;
	time_t time_begin,time_end,t0;

	time_begin=time(NULL);
	for(t=0;t<1000000;t++)
	{
		;
	}
	time_end=time(NULL);
	t0=time_end-time_begin;
	time_begin=time(NULL);
	for(t=0;t<1000000;t++)
	{
		rabin_3072(msg, digest, 96);
	}
	time_end=time(NULL);t=time_end-time_begin-t0;
	printf("\nThe time of generating message digest is %I64d us\n", t);
	printf("\nThe message digest is:\n");
	for(i = 0; i < 96; i++)
		printf("%08x ",digest[95 - i]);
	printf("\n\n");
}	

*/
