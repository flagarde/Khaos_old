/*
* Khaos
* C/C++ library for writing cross-platform codes.
*
* SPDX-FileCopyrightText: 2020-2024 flagarde
*
* SPDX-License-Identifier: MIT
*/

/* Copyright 2022 flagarde */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Khaos/Compiler.h"

// NOLINTBEGIN
#include "doctest/doctest.h"
// NOLINTEND

#include <iostream>

TEST_CASE("Test COMPILER_IS(...)")
{
#if COMPILER_IS(NVCC)
  std::cout << "Compiler is NVCC " << GET_VERSION_MAJOR(NVCC) << "." << GET_VERSION_MINOR(NVCC) << "." << GET_VERSION_PATCH(NVCC) << "." << GET_VERSION_TWEAK(NVCC) << std::endl;
#endif

#if COMPILER_IS(ACC)
  std::cout << "Compiler is ACC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(AltiumMicroblaze)
  std::cout << "Compiler is AltiumMicroblaze " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Altium)
  std::cout << "Compiler is Altium " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Amsterdam)
  std::cout << "Compiler is Amsterdam " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(ARM)
  std::cout << "Compiler is ARM " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Aztec)
  std::cout << "Compiler is Aztec " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Borland)
  std::cout << "Compiler is Borland " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(CC65)
  std::cout << "Compiler is CC65 " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Comeau)
  std::cout << "Compiler is Comeau " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Compaq)
  std::cout << "Compiler is Compaq " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Convex)
  std::cout << "Compiler is Convex " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Compcert)
  std::cout << "Compiler is Compcert " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Coverity)
  std::cout << "Compiler is Coverity " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(CrayC)
  std::cout << "Compiler is CrayC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Diab)
  std::cout << "Compiler is Diab " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(DICE)
  std::cout << "Compiler is DICE " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(DigitalMars)
  std::cout << "Compiler is DigitalMars " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Dignus)
  std::cout << "Compiler is Dignus " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(DJGPP)
  std::cout << "Compiler is DJGPP " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(EDG)
  std::cout << "Compiler is EDG " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(EKOPath)
  std::cout << "Compiler is EKOPath " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Emscripten)
  std::cout << "Compiler is Emscripten " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Fujitsu)
  std::cout << "Compiler is Fujitsu " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(GCCXML)
  std::cout << "Compiler is GCCXML " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(GreenHills)
  std::cout << "Compiler is GreenHills " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(HPCC)
  std::cout << "Compiler is HPCC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(HPaCC)
  std::cout << "Compiler is HPaCC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(IAR)
  std::cout << "Compiler is IAR " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(IBM)
  std::cout << "Compiler is IBM " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(IBMClang)
  std::cout << "Compiler is IBMClang " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(IBMLegacy)
  std::cout << "Compiler is IBMLegacy " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(IBMC370)
  std::cout << "Compiler is IBMC370 " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(IBMMVS)
  std::cout << "Compiler is IBMMVS " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(IBMOS390)
  std::cout << "Compiler is IBMOS390 " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(IBMZOS)
  std::cout << "Compiler is IBMZOS " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(ImageCraft)
  std::cout << "Compiler is ImageCraft " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Intel)
  std::cout << "Compiler is Intel " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Intellisense)
  std::cout << "Compiler is Intellisense " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Kai)
  std::cout << "Compiler is Kai " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(KeilCarm)
  std::cout << "Compiler is KeilCarm " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(KeilC166)
  std::cout << "Compiler is KeilC166 " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(KeilC51)
  std::cout << "Compiler is KeilC51 " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(LCC)
  std::cout << "Compiler is LCC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Metaware)
  std::cout << "Compiler is Metaware " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Metrowerks)
  std::cout << "Compiler is Metrowerks " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(MSVC)
  std::cout << "Compiler is MSVC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Microtec)
  std::cout << "Compiler is Microtec " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Microway)
  std::cout << "Compiler is Microway " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(MIPSpro)
  std::cout << "Compiler is MIPSpro " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Miracle)
  std::cout << "Compiler is Miracle " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(MPW)
  std::cout << "Compiler is MPW " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Norcroft)
  std::cout << "Compiler is Norcroft " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(NWCC)
  std::cout << "Compiler is NWCC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Open64)
  std::cout << "Compiler is Open64 " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Oracle)
  std::cout << "Compiler is Oracle " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Solaris)
  std::cout << "Compiler is Solaris " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Pacific)
  std::cout << "Compiler is Pacific " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Palm)
  std::cout << "Compiler is Palm " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Pelles)
  std::cout << "Compiler is Pelles " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Portland)
  std::cout << "Compiler is Portland " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Renesas)
  std::cout << "Compiler is Renesas " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(SASC)
  std::cout << "Compiler is SASC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(SCO)
  std::cout << "Compiler is SCO " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(SDCC)
  std::cout << "Compiler is SDCC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(SNC)
  std::cout << "Compiler is SNC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Stratus)
  std::cout << "Compiler is Stratus " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(StratusKR)
  std::cout << "Compiler is StratusKR " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(StratusANSI)
  std::cout << "Compiler is StratusANSI " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Symantec)
  std::cout << "Compiler is Symantec " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Tendra)
  std::cout << "Compiler is Tendra " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(TI)
  std::cout << "Compiler is TI " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Think)
  std::cout << "Compiler is Think " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(TinyC)
  std::cout << "Compiler is TinyC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Turbo)
  std::cout << "Compiler is Turbo " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Ultimate)
  std::cout << "Compiler is Ultimate " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(USLC)
  std::cout << "Compiler is USLC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(VBCC)
  std::cout << "Compiler is VBCC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Watcom)
  std::cout << "Compiler is Watcom " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Zortech)
  std::cout << "Compiler is Zortech " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(AppleClang)
  std::cout << "Compiler is AppleClang " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Clang)
  std::cout << "Compiler is Clang " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(LLVM)
  std::cout << "Compiler is LLVM " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(GCC)
  std::cout << "Compiler is GCC " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(Unknown)
  std::cout << "Compiler is Unknown " << GET_VERSION_MAJOR(Compiler) << "." << GET_VERSION_MINOR(Compiler) << "." << GET_VERSION_PATCH(Compiler) << "." << GET_VERSION_TWEAK(Compiler) << std::endl;
#endif

#if COMPILER_IS(ClangEmulated)
  std::cout << "Compiler is ClangEmulated " << GET_VERSION_MAJOR(ClangEmulated) << "." << GET_VERSION_MINOR(ClangEmulated) << "." << GET_VERSION_PATCH(ClangEmulated) << "." << GET_VERSION_TWEAK(ClangEmulated) << std::endl;
#endif

#if COMPILER_IS(GCCEmulated)
  std::cout << "Compiler is GCCEmulated " << GET_VERSION_MAJOR(GCCEmulated) << "." << GET_VERSION_MINOR(GCCEmulated) << "." << GET_VERSION_PATCH(GCCEmulated) << "." << GET_VERSION_TWEAK(GCCEmulated) << std::endl;
#endif

#if COMPILER_IS(LLVMEmulated)
  std::cout << "Compiler is LLVMEmulated " << GET_VERSION_MAJOR(LLVMEmulated) << "." << GET_VERSION_MINOR(LLVMEmulated) << "." << GET_VERSION_PATCH(LLVMEmulated) << "." << GET_VERSION_TWEAK(LLVMEmulated) << std::endl;
#endif
}
