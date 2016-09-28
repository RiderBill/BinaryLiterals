// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
// Formerly stdafx.h. I assume the unit test project will need everything included
// in the project under test's pch, plus a few more things, so I'm giving this
// file a different name and making it the pch for the unit test project.
#pragma once

#include "targetver.h"

// Headers for CppUnitTest
#include "CppUnitTest.h"

// TODO: reference additional headers your program requires here
#include "StdAfx.h" // This is the pch for the project under test.
#include "BinaryIntClass.h"