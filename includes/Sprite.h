#pragma once

#include "Texture.h"
#include <cstddef>
#include <vector>

namespace doengine
{

enum class ClipType
{
    Contiguous,
    Free
};

class Sprite
{
  public:
    Sprite(Texture* texture, const std::vector<Rect>& frames,
           const Point& offset, const ClipType = ClipType::Contiguous);

    ~Sprite();

    virtual void Draw(const Point& pos);
    virtual void Update(const long deltaTime);

    virtual void SetClipType(const ClipType type);
    virtual ClipType GetClipType() const;

    virtual Texture* GetTexture() const;

  protected:
    const std::vector<Rect> frames;
    Texture* texture;
    const Point& offset;
    ClipType clipType;
    size_t animId;
};
} // namespace doengine
