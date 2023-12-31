/*
 * Copyright 2011-2020 Blender Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __UTIL_TBB_H__
#define __UTIL_TBB_H__

/* TBB includes <windows.h>, do it ourselves first so we are sure
 * WIN32_LEAN_AND_MEAN and similar are defined beforehand. */
#include "util_windows.h"

#ifndef __TBB_SOURCE_DIRECTLY_INCLUDED
#define __TBB_SOURCE_DIRECTLY_INCLUDED 1
#endif
#ifndef __TBB_DYNAMIC_LOAD_ENABLED
#define __TBB_DYNAMIC_LOAD_ENABLED 0
#endif

#include <tbb/enumerable_thread_specific.h>
#include <tbb/parallel_for.h>
#include <tbb/task_arena.h>
#include <tbb/task_group.h>

#if TBB_INTERFACE_VERSION_MAJOR >= 10
#  define WITH_TBB_GLOBAL_CONTROL
#  include <tbb/global_control.h>
#endif

CCL_NAMESPACE_BEGIN

using tbb::blocked_range;
using tbb::enumerable_thread_specific;
using tbb::parallel_for;

static inline void parallel_for_cancel()
{
#if TBB_INTERFACE_VERSION_MAJOR >= 12
  tbb::task_group_context *ctx = tbb::task::current_context();
  if (ctx) {
    ctx->cancel_group_execution();
  }
#else
  tbb::task::self().cancel_group_execution();
#endif
}

CCL_NAMESPACE_END

#endif /* __UTIL_TBB_H__ */
