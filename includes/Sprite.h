#pragma once

#include <map>
#include <vector>

#include "Renderer.h"
#include "Texture.h"

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
    Sprite(Texture* texture, const std::vector<Rect>& frames, Point& offset,
           Renderer& renderer, const ClipType = ClipType::Contiguous);

    ~Sprite();

    virtual void Draw(const Point& pos);
    virtual void Update(const long deltaTime);

    virtual void SetClipType(const ClipType type);
    virtual ClipType GetClipType() const;

    virtual Texture* GetTexture() const;

  protected:
    Renderer& renderer;
    const std::vector<Rect>& frames;
    Texture* texture;
    Point& offset;
    ClipType clipType;
};
} // namespace doengine
