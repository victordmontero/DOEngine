#pragma once
#include <Canvas.h>
#include <GameState.h>
#include <vector>
class SortedState : public GameState
{
    struct ColumnEntry
    {
        SDL_Rect offset;
        int value;
    };

    int width;
    int inner_width;
    int window_width;
    int height;

    std::vector<ColumnEntry*> entries;

    Canvas* ctx;

  public:
    SortedState(doengine::AbstractWindow* w) : window(w)
    {
    }

    virtual void OnEnter() override;
    virtual void OnExit() override;
    virtual void Update(float elapsed) override;
    virtual void Render() override;

  private:
    doengine::AbstractWindow* window;
};