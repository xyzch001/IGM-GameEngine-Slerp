// Copyright � 2008 Intel Corporation
// All Rights Reserved
// 
// The sample source code contained or described herein and all documents
// related to the sample source code ("Material") are owned by Intel Corporation
// or its suppliers or licensors. Title to the Material remains with Intel Corporation
// or its suppliers and licensors. The Material may contain trade secrets and
// proprietary and confidential information of Intel Corporation and its suppliers
// and licensors, and is protected by worldwide copyright and trade secret laws and
// treaty provisions. The sample source code is provided AS IS, with no warranties
// of any kind, express or implied. Except as expressly permitted by the Software
// license, neither Intel Corporation nor its suppliers assumes any responsibility
// or liability for any errors or inaccuracies that may appear herein.

#pragma once

typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

#if defined( _WIN64 )
typedef u64 uptr;
#else
//typedef W64SAFE u32 uptr;
#endif

typedef float f32;
typedef double f64;

typedef u32 Bool;     // Defines: True and False
typedef void* Handle;
typedef u32 Error;

typedef u32 Id;      // Local id, GUIDs are too slow and unnecessary for our purposes.

typedef char* pstr;
typedef const char* pcstr;

typedef void(*Callback)(void* pUserData);
