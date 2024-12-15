#ifndef LEAVE_H_INCLUDED
#define LEAVE_H_INCLUDED
#include "scene.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/*
   [Menu object]
*/
typedef struct _Leave
{
    ALLEGRO_FONT *font;

    ALLEGRO_BITMAP *background_image; //【新增儲存圖片的變數】
    ALLEGRO_BITMAP *button[2]; //【存放四種按鈕】
    ALLEGRO_BITMAP *hightlight_button[2]; //【四種按鈕在滑鼠在上方時會發光】
    bool over_button[2]; //【該按鈕是否與滑鼠位置重疊】
    int X[2], Y[2]; //【按鈕各自的XY座標】
    int XH[2], YH[2];
    int button_W[2], button_H[2]; //【按鈕圖片的長寬(固定)】
    int buttonH_W[2], buttonH_H[2];

    int click;

    //設定按鈕聲音
    ALLEGRO_SAMPLE *ButtonClick;
    ALLEGRO_SAMPLE_INSTANCE *Click_sample_instance;

    int title_x, title_y;
} Leave;

Scene *New_Leave(int label);
void Leave_update(Scene *self);
void Leave_draw(Scene *self);
void Leave_destroy(Scene *self);

void Leave_DetectButtonOn(Scene *self);

#endif
