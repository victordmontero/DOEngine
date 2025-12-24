#ifndef TEXTFIELD_UI_H_DEFINED
#define TEXTFIELD_UI_H_DEFINED

#include "Application.h"
#include "Event.h"
#include "Geometric.h"
#include "Renderer.h"
#include "TTFText.h"
#include <functional>
#include <string>

namespace doengine
{

class TextField : public MouseEvent,
                  public KeyboardInputhandlingEvent,
                  public TextInputEvent
{
  private:
    virtual void MouseMove(const Mouse& mouse);
    virtual void MouseButtonDown(const Mouse& mouse);
    virtual void MouseButtonUp(const Mouse&);
    virtual void MouseWheel(const Mouse&);

    virtual void OnKeydown(const Keyboard& keyboard);
    virtual void OnKeyup(const Keyboard&);
    virtual void OnTextInput(const std::string& text);

  public:
    TextField(int x, int y, int w, int h, const std::string& font);

    void Render();

    std::string getText() const;

    void setOnEnterKeyPressed(std::function<void(const std::string&)> fn);

  private:
    Rect rect;
    Color textColor;
    Color bgColor;
    Color borderColor;
    std::string text;
    bool focused;

    std::string fontsrc;
    TTFText* font;
    Renderer* renderer;

    std::function<void(const std::string&)> onEnterPressed;
};

} // namespace doengine

#endif