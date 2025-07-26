#include "Sprite.h"

namespace doengine
{

Sprite::Sprite(Texture* texture, const std::vector<Rect>& frames, Point& offset,
               Renderer& renderer, const ClipType type)
    : renderer(renderer), texture(texture), frames(frames), offset(offset),
      clipType(type)
{
}

Sprite::~Sprite()
{
    texture = nullptr;
}

void Sprite::Draw(const Point& pos)
{
    switch (clipType)
    {
    case ClipType::Contiguous:
        for (auto it = frames.begin(); it != frames.end(); it++)
        {
            Rect dstRect{offset.x, offset.y, (*it).w, (*it).h};
            texture->Draw(dstRect, *it);
        }
        break;

    case ClipType::Free:
    default:

        break;
    }
}
void Sprite::Update(const long deltaTime)
{
}

void Sprite::SetClipType(const ClipType type)
{
    clipType = type;
}

ClipType Sprite::GetClipType() const
{
    return clipType;
}

Texture* Sprite::GetTexture() const
{
    return texture;
}

} // namespace doengine
