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

#include "render/image_oiio.h"

#include "util/util_image.h"
#include "util/util_logging.h"
#include "util/util_path.h"

CCL_NAMESPACE_BEGIN

OIIOImageLoader::OIIOImageLoader(const string &filepath) : filepath(filepath)
{
}

OIIOImageLoader::~OIIOImageLoader()
{
}

bool OIIOImageLoader::load_metadata(const ImageDeviceFeatures &features, ImageMetaData &metadata)
{
  return false;
}

template<TypeDesc::BASETYPE FileFormat, typename StorageType>
static void oiio_load_pixels(const ImageMetaData &metadata,
                             const unique_ptr<ImageInput> &in,
                             StorageType *pixels)
{
  const int width = metadata.width;
  const int height = metadata.height;
  const int depth = metadata.depth;
  const int components = metadata.channels;

  /* Read pixels through OpenImageIO. */
  StorageType *readpixels = pixels;
  vector<StorageType> tmppixels;
  if (components > 4) {
    tmppixels.resize(((size_t)width) * height * components);
    readpixels = &tmppixels[0];
  }

  if (depth <= 1) {
    size_t scanlinesize = ((size_t)width) * components * sizeof(StorageType);
    in->read_image(FileFormat,
                   (uchar *)readpixels + (height - 1) * scanlinesize,
                   AutoStride,
                   -scanlinesize,
                   AutoStride);
  }
  else {
    in->read_image(FileFormat, (uchar *)readpixels);
  }

  if (components > 4) {
    size_t dimensions = ((size_t)width) * height;
    for (size_t i = dimensions - 1, pixel = 0; pixel < dimensions; pixel++, i--) {
      pixels[i * 4 + 3] = tmppixels[i * components + 3];
      pixels[i * 4 + 2] = tmppixels[i * components + 2];
      pixels[i * 4 + 1] = tmppixels[i * components + 1];
      pixels[i * 4 + 0] = tmppixels[i * components + 0];
    }
    tmppixels.clear();
  }

  /* CMYK to RGBA. */
  const bool cmyk = strcmp(in->format_name(), "jpeg") == 0 && components == 4;
  if (cmyk) {
    const StorageType one = util_image_cast_from_float<StorageType>(1.0f);

    const size_t num_pixels = ((size_t)width) * height * depth;
    for (size_t i = num_pixels - 1, pixel = 0; pixel < num_pixels; pixel++, i--) {
      float c = util_image_cast_to_float(pixels[i * 4 + 0]);
      float m = util_image_cast_to_float(pixels[i * 4 + 1]);
      float y = util_image_cast_to_float(pixels[i * 4 + 2]);
      float k = util_image_cast_to_float(pixels[i * 4 + 3]);
      pixels[i * 4 + 0] = util_image_cast_from_float<StorageType>((1.0f - c) * (1.0f - k));
      pixels[i * 4 + 1] = util_image_cast_from_float<StorageType>((1.0f - m) * (1.0f - k));
      pixels[i * 4 + 2] = util_image_cast_from_float<StorageType>((1.0f - y) * (1.0f - k));
      pixels[i * 4 + 3] = one;
    }
  }
}

bool OIIOImageLoader::load_pixels(const ImageMetaData &metadata,
                                  void *pixels,
                                  const size_t,
                                  const bool associate_alpha)
{
  return false;
}

string OIIOImageLoader::name() const
{
  return path_filename(filepath.string());
}

ustring OIIOImageLoader::osl_filepath() const
{
  return filepath;
}

bool OIIOImageLoader::equals(const ImageLoader &other) const
{
  const OIIOImageLoader &other_loader = (const OIIOImageLoader &)other;
  return filepath == other_loader.filepath;
}

CCL_NAMESPACE_END
