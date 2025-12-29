#pragma once
#include <string>
#include "Texture.h"

namespace ote::renderer {
struct Material {
    Texture albedo;
    float metallic = 0.0f;
    float roughness = 1.0f;
};
}
