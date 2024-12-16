// #ifndef OPERATIONCENTER_H_INCLUDED
// #define OPERATIONCENTER_H_INCLUDED
// #include "scene.h"

// class SceneCenter
// {
// public:
//   static SceneCenter *get_instance()
//   {
//     static SceneCenter OC;
//     return &OC;
//   }

//   Scene *new_scene(int label);
//   void update();
//   void draw();
//   void destroy();
//   void DetectButtonOn();

// private:
//   SceneCenter() {}

// private:
//   Scene *New_Menu(int label);
//   Scene *New_Leave(int label);
//   Scene *New_Info(int label);
//   Scene *New_GameScene(int label);
//   Scene *New_Setting(int label);

// private:
//   void menu_update(Scene *self);
//   void Leave_update(Scene *self);
//   void Info_update(Scene *self);
//   void game_scene_update(Scene *self);
//   void Setting_update(Scene *self);

// private:
//   void menu_draw(Scene *self);
//   void Leave_draw(Scene *self);
//   void Info_draw(Scene *self);
//   void game_scene_draw(Scene *self);
//   void Setting_draw(Scene *self);

// private:
//   void menu_destroy(Scene *self);
//   void Leave_destroy(Scene *self);
//   void Info_destroy(Scene *self);
//   void game_scene_destroy(Scene *self);
//   void Setting_destroy(Scene *self);

// private:
//   void DetectButtonOn(Scene *self);
//   void Leave_DetectButtonOn(Scene *self);
//   void Info_DetectButtonOn(Scene *self);
//   void Game_DetectButtonOn(Scene *self);
//   void Setting_DetectButtonOn(Scene *self);
// };

// #endif
