#ifndef SFMLGUI_ENGINE_H
#define SFMLGUI_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>



#include "windows.h"
using namespace std;
using namespace sf;
using namespace std::chrono;


class Engine {



private:
    bool trigger = true;
    bool running = true;
    bool quit_flag = false;
    bool allow_color_change =true ;
    int wow_i = 0;
    int asked = 0;
    int score = 0;
    int timed = 0;
    int difficulty = 1;
    Vector2f resolution;
    RenderWindow game_window;
    RenderWindow main_window;
    RenderWindow lvl_window;
    RenderWindow score_window;
    RenderWindow history_window;
    const unsigned int FPS = 60;
    static const Time TimePerFrame;
    Texture texture_bg;
    Texture texture_score_bg;
    Texture texture_main;
    Texture texture_drug0;
    Texture texture_drug1;
    Texture texture_drug2;
    Texture texture_drug3;
    Texture texture_drug4; 
    Texture texture_drug5;          
    Texture texture_lvl;
    Texture texture_mute;
    Texture texture_unmute;
    Texture texture_history;
    Sprite bg;
    Sprite score_bg;
    Sprite history_bg;
    Sprite main;
    Sprite drug1;
    Sprite lvl;
    Sprite play;
    Font font_arl;
    Text text;
    Text ask;
    Text answer;
    Text helper;
    Text user_score;
    Text historyx;
    string final_answer;
    string randomDrugs[30][3];
    string drugNeeded[12][3];
    string frint;
public:
    Engine();
    void main_input();
    void game_input();
    void lvl_input();
    void history_input();
    void score_input();
    void draw_drugs();
    void random_drug_pic();
    void draw_text();
    void draw_amount();
    void draw_background();
    void draw_main_assets();
    void create_main();
    void create_History_window();
    void read();
    void create_game_window();
    void create_selector();
    void create_end_game();
    void run();
    void get_drugs(string drugs[][3],string n_drugs[][3]);
    void check_drugs(int arg);
    void save_info();
    void compare_drugs(string user_answer, int asked, int arg, int level,float duration );

};


#endif
