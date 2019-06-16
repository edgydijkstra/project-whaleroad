#pragma once

#include "block.h"
#include "common/constants.h"


#include <Magnum/Magnum.h>
#include <Magnum/Math/Vector3.h>
#include <Magnum/Math/Range.h>
#include <Corrade/Containers/ArrayView.h>
#include <Corrade/Utility/Resource.h>
#include <Magnum/GL/AbstractShaderProgram.h>
#include <Magnum/GL/Context.h>
#include <Magnum/GL/Shader.h>
#include <Magnum/GL/Texture.h>
#include <Magnum/GL/TextureFormat.h>
#include <Magnum/GL/ImageFormat.h>
#include <Magnum/GL/Version.h>
#include <Magnum/GL/PixelFormat.h>
#include <Magnum/Math/Color.h>
#include <Magnum/ImageView.h>
#include <Magnum/Image.h>
#include <Magnum/PixelStorage.h>
class world_page;
class world;

std::string read_text_file(std::string filename);
class block_iterator {
public:
    
  typedef void (*column_operation)(block_t *, uint16_t *, uint16_t *,
                                   int, int, int, int, world_page *, world *);
  static void iter_columns(world *wld, Magnum::Range3Di bounds, column_operation op,
                           int neighborhood_size,  bool diff_only = false);
};

