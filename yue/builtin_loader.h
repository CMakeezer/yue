// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef YUE_BUILTIN_LOADER_H_
#define YUE_BUILTIN_LOADER_H_

#include "lua/lua.h"

namespace yue {

// Add a function to package.searchers to load builtin modules of yue.
void InsertBuiltinModuleLoader(lua::State* state);

}  // namespace yue

#endif  // YUE_BUILTIN_LOADER_H_
