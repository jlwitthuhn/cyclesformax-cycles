/*
 * Copyright 2011-2013 Blender Foundation
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

#ifndef __UTIL_PARAM_H__
#define __UTIL_PARAM_H__

/* Parameter value lists from OpenImageIO are used to store custom properties
 * on various data, which can then later be used in shaders. */
#pragma warning( push )
#pragma warning( disable: 4100 4267 4800 )

#include <OpenImageIO/paramlist.h>
#include <OpenImageIO/typedesc.h>
#include <OpenImageIO/ustring.h>

#pragma warning( pop )

CCL_NAMESPACE_BEGIN

OIIO_NAMESPACE_USING

static constexpr TypeDesc TypeFloat2(TypeDesc::FLOAT, TypeDesc::VEC2);
static constexpr TypeDesc TypeRGBA(TypeDesc::FLOAT, TypeDesc::VEC4, TypeDesc::COLOR);
static constexpr TypeDesc TypeFloatArray4(TypeDesc::FLOAT,
                                          TypeDesc::SCALAR,
                                          TypeDesc::NOSEMANTICS,
                                          4);

CCL_NAMESPACE_END

#endif /* __UTIL_PARAM_H__ */
