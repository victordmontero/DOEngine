#include "GameObject.h"
#include "MessageBox.h"
#include "Application.h"
#include "DraggableGameObject.h"
#include "Event.h"
#include "FontCache.h"
#include "GameState.h"
#include "Logger.h"
#include "Mouse.h"
#include "SelectionRect.h"
#include "SpriteOffset.h"
#include "TTFText.h"
#include "Texture.h"
#include "Tile.h"
#include "Tilemap.h"
#include "UI.h"
#include "TextField.h"
#include "TileMapEditor.h"
#include "DOEngine_SDL_includes.h"
#include <unordered_map>
#include <vector>
#include <memory>


using doengine::Application;
using doengine::Rect;
using doengine::Renderer;
using doengine::GameState;
using doengine::SpriteAnimationOffset;
using doengine::Color;
using doengine::KeyDownEvent;
using doengine::MouseEvent;
using doengine::KeyboardInputhandlingEvent;
using doengine::TextInputEvent;
using doengine::TileMapEditor;
using doengine::TextureManager;
using doengine::TileCharTextureOffset;
using doengine::Texture;
using doengine::SelectionRect;
using doengine::GameObject;
using doengine::checkCollision;



struct BattleCityMainPlayer : 
 public GameObject//,
 /////public KeyboardInputhandlingEvent
{
    virtual void Update(float timer = 0);
    virtual void Render();
  
};

void BattleCityMainPlayer::Update(float timer)
{

}

void BattleCityMainPlayer::Render()
{

}

 




struct PlayState : 
    public GameState,
    public KeyboardInputhandlingEvent
{
    Texture* texture;
    SelectionRect *helperSelection;

    /// Player
    BattleCityMainPlayer *player;
    
    void loadTileMapResource();
    void loadDebugResource();


    virtual void OnEnter();
    virtual void OnExit();
    virtual void Update(float elapsed);
    virtual void Render();
    virtual void OnKeydown(const Keyboard&);
    virtual void OnKeyup(const Keyboard&);
};

void PlayState::loadDebugResource()
{
   helperSelection = new SelectionRect();
   helperSelection->setFont("./assets/fonts/DroidSans.ttf");
   helperSelection->setFontColor(doengine::Colors::red);
}

void PlayState::loadTileMapResource()
{

}

void PlayState::OnEnter()
{
    loadTileMapResource();
    loadDebugResource();

    player = new BattleCityMainPlayer();

}
void PlayState::OnExit()
{

}
void PlayState::Update(float elapsed)
{

    player->Update(elapsed);
}
void PlayState::Render()
{

}
void PlayState::OnKeydown(const Keyboard&)
{

}
void PlayState::OnKeyup(const Keyboard&)
{

}


int main(int argc, char *argv[])
{
    auto app = doengine::Application::getApplication();
    auto resoltion = doengine::Application::getApplication()->getDisplayMode(0);
    doengine::Rect rect{resoltion.w/2, resoltion.h};
    app->createWindow(rect);
    auto playstate = new PlayState();
    app->addState(playstate, 1);
    app->setState(1);

    while (app->IsRunning())
    {
        app->PollEvent();
        app->Update();
        app->clearScreen(doengine::Colors::black);
        app->Render();
    }
    app->Quit();
    return 0;
    return 0;
}


