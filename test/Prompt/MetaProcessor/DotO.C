//------------------------------------------------------------------------------
// CLING - the C++ LLVM-based InterpreterG :)
//
// This file is dual-licensed: you can choose to license it under the University
// of Illinois Open Source License or the GNU Lesser General Public License. See
// LICENSE.TXT for details.
//------------------------------------------------------------------------------

// RUN: cat %s | %cling 2>&1 | FileCheck %s

extern "C" int printf(const char*,...);
#include "cling/Interpreter/Interpreter.h"
#include "cling/Interpreter/Transaction.h"

gCling->getDefaultOptLevel() // CHECK: (int) 2
.O // CHECK-NEXT: Current cling optimization level: 2
(int)gCling->getLatestTransaction()->getCompilationOpts().OptLevel // CHECK-NEXT: (int) 2

.O 0
gCling->getDefaultOptLevel() // CHECK: (int) 0
.O // CHECK-NEXT: Current cling optimization level: 0

#pragma cling optimize(1)
gCling->getDefaultOptLevel() // CHECK: (int) 0
.O // CHECK-NEXT: Current cling optimization level: 0
