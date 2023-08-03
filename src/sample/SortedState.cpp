#include <SortedState.h>
#include <StandardFuncs.h>


 void SortedState::OnEnter(){

    Event::AddKeydownEventListener(this);
    this->ctx  =new Canvas(window);
    this->ctx->setCanvasBackgroundColor(Canvas::black);

    this->height = window->getH()-100;
    current_index = 0;
    width = 48;

    int nTimes = (window->getW()/width) - 4;
  
    for(int i=0;i<nTimes;i++)
    {
        ColumnEntry *entry =new ColumnEntry();
        entry->offset.x = i * width;
        entry->offset.y = 0;
        entry->offset.w = width;
        entry->value = getRandomInt(10, 1000);
        entry->offset.h = getPercentageFrom(entry->value, 1000);
        this->entries.push_back(entry);
       /// SDL_Log("value = %ld, height=%ld", entry->value, entry->offset.h);
    }

 ctx->fillColor({200,200, (unsigned char)getRandomInt(0,234), 255});
 }
 void SortedState::OnExit(){

 }

void SortedState::OnKeydown(int code){
   /// SDL_Log("Key Pressed %ld", code);

    if(code == 97)
       next =true;
}

 void SortedState::Update(float elapsed)
 {


    if(next==false)return;
    if(current_index >= entries.size())
       return ;

     SDL_Log("Updating %ld %ld", entries[current_index]->value, entries[current_index+1]->value );
    if(entries[current_index]->value > entries[current_index+1]->value )
    {
        std::swap(entries[current_index], entries[current_index+1]);
        // auto ptr1 = entries[current_index];
        // auto ptr2 = entries[current_index+1];

        // entries[current_index] = ptr2;
        // entries[current_index+1] = ptr1;

        // int h = entries[current_index]->offset.h;
        // int x = entries[current_index]->offset.x;
        // int v = entries[current_index]->value;

        // entries[current_index]->offset.h = entries[current_index+1]->offset.h;
        // entries[current_index]->offset.x= entries[current_index+1]->offset.x;
        // entries[current_index]->value= entries[current_index+1]->value;

        // entries[current_index+1]->offset.h = h;
        // entries[current_index+1]->offset.x= x;
        // entries[current_index+1]->value=v;
    }

    current_index++;
    next =false;
  

 }
 void SortedState::Render(){
   ctx->clearCanvas(); 
    for(auto it : entries)
    {
        ctx->DrawRect(it->offset.x+100, it->offset.y+100, it->offset.w, it->offset.h, false);

        ctx->DrawRect(it->offset.x+108, it->offset.y+104, it->offset.w-12, it->offset.h-14, true);
    }
    ctx->update();
    ctx->clearCanvas();
 }