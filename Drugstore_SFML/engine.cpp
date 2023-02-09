#include "engine.h"



const sf::Time Engine::TimePerFrame = sf::seconds(1.f / 60.f);



Engine::Engine()
{

    texture_main.loadFromFile("../assets/Main-Menu.jpg",IntRect(0,0,1280,720));
    main.setTexture(texture_main);

    texture_lvl.loadFromFile("../assets/level-Select.jpg",IntRect(0,0,1280,720));
    lvl.setTexture(texture_lvl);

    texture_bg.loadFromFile("../assets/DS-Shelves.jpg", IntRect(0, 0, 1044, 560));
    bg.setTexture(texture_bg);

    texture_score_bg.loadFromFile("../assets/Score-Board.jpg",IntRect(0, 0, 960, 640));
    score_bg.setTexture(texture_score_bg);

    texture_history.loadFromFile("../assets/history_board.jpg",IntRect(0, 0, 960, 640));
    history_bg.setTexture(texture_history);

    texture_drug0.loadFromFile("../assets/Drug0.png",IntRect(0, 0, 4300, 8100));
    drug1.setScale(Vector2f(0.0075,0.0075));  

    texture_drug1.loadFromFile("../assets/Drug1.png",IntRect(0, 0, 4300, 8100));
    drug1.setScale(Vector2f(0.0075,0.0075));

    texture_drug2.loadFromFile("../assets/Drug2.png",IntRect(0, 0, 4300, 8100));
    drug1.setScale(Vector2f(0.0075,0.0075));

    texture_drug3.loadFromFile("../assets/Drug3.png",IntRect(0, 0, 4300, 8100));
    drug1.setScale(Vector2f(0.0075,0.0075)); 

    texture_drug4.loadFromFile("../assets/Drug4.png",IntRect(0, 0, 4300, 8100));
    drug1.setScale(Vector2f(0.0075,0.0075));

    texture_drug5.loadFromFile("../assets/Drug5.png",IntRect(0, 0, 4300, 8100));
    drug1.setScale(Vector2f(0.0075,0.0075));

    texture_mute.loadFromFile("../assets/Mute.png",IntRect(0,0,1601,1409));
    texture_unmute.loadFromFile("../assets/Unmute.png",IntRect(0,0,1601,1409));
    play.setTexture(texture_unmute);
    play.setScale(Vector2f(0.04,0.04));
    play.setPosition(55,630);
    
    font_arl.loadFromFile("../assets/arial.ttf");
    text.setString("SECRET TEXT");
    text.setFont(font_arl);
    text.setCharacterSize(13);
    text.setFillColor(Color::Black);
    text.setOutlineColor(Color::Black);
    //Load a sprite to display
    //load background
    ask.setFont(font_arl);
    ask.setCharacterSize(20);
    ask.setFillColor(Color::Red);
    ask.setOutlineColor(Color::Black);
    ask.setPosition(70,480);
    ask.setString("SECRET TEXT");

    answer.setFont(font_arl);
    answer.setCharacterSize(20);
    answer.setFillColor(Color::Red);
    answer.setOutlineColor(Color::Black);
    answer.setPosition(270,480);
    answer.setString("");

    helper.setFont(font_arl);
    helper.setString("Please enter the amount");
    helper.setCharacterSize(20);
    helper.setFillColor(Color::Green);
    helper.setPosition(40,40);

    user_score.setFont(font_arl);
    user_score.setString("YOUR SCORE IS : ");
    user_score.setCharacterSize(50);
    user_score.setFillColor(Color::White);
    user_score.setPosition(200,90);

    


}

void Engine::random_drug_pic(){

   int random = rand() % 6;
    switch (random)
    {
    case 0:

    drug1.setTexture(texture_drug0);
   

        break;
    
    case 1:

    drug1.setTexture(texture_drug1);
    
        break;

    case 2:

    drug1.setTexture(texture_drug2);
    
        break;

    case 3:

    drug1.setTexture(texture_drug3);
   
        break;

    case 4:

    drug1.setTexture(texture_drug4);
    
        break;

    case 5:

    drug1.setTexture(texture_drug5);
    
        break;
    }

}
void Engine::get_drugs(string drugs[][3],string n_drugs[][3]){

    for (int x=0 ; x < 30; x++)
    {
        for (int y=0 ; y < 3; y++)
        {
            randomDrugs[x][y] = drugs[x][y];
        }
    }

    for (int x=0 ; x < 12; x++)
    {
        for (int y=0 ; y < 3; y++)
        {
            drugNeeded[x][y] = n_drugs[x][y];
        }
    }
}

void Engine::draw_drugs(){

    float x_grid = 53;
    float space_grid = 100;

    for (int i = 0; i < 10 ; i++) {
        if(allow_color_change == true){
            random_drug_pic();
            }
        drug1.setPosition(x_grid, 120);
        game_window.draw(drug1); // draws drug
        x_grid = x_grid + space_grid;

    }
    x_grid = 50;

    for (int j = 0; j < 10 ; j++) {
         if(allow_color_change == true){
        random_drug_pic();
         }
        drug1.setPosition(x_grid, 230);
        game_window.draw(drug1); // draws drug
        x_grid = x_grid + space_grid;

    }

    x_grid = 50;

    for (int k = 0; k < 10 ; k++) {
         if(allow_color_change == true){
        random_drug_pic();
         }
        drug1.setPosition(x_grid, 345);
        game_window.draw(drug1); // draws drug
        x_grid = x_grid + space_grid;

    }


}

void Engine::draw_text(){

    float x_grid = 36;
    float space_grid = 100;

    for (int i = 0; i < 10 ; i++) {

        text.setString(randomDrugs[i][0]);
        text.setPosition(x_grid, 182);
        game_window.draw(text); // draws drug
        x_grid = x_grid + space_grid;

    }
    x_grid = 36;

    for (int j = 10; j < 20 ; j++) {

        text.setString(randomDrugs[j][0]);
        text.setPosition(x_grid, 293);
        game_window.draw(text); // draws drug
        x_grid = x_grid + space_grid;

    }

    x_grid = 36;

    for (int k = 20; k < 30 ; k++) {

        text.setString(randomDrugs[k][0]);
        text.setPosition(x_grid, 407);
        game_window.draw(text); // draws drug
        x_grid = x_grid + space_grid;

    }


}

void Engine::draw_amount(){

    float x_grid = 53;
    float space_grid = 100;

    for (int i = 0; i < 10 ; i++) {

        text.setString("("+randomDrugs[i][1]+"x)");
        text.setPosition(x_grid, 197);
        game_window.draw(text); // draws drug
        x_grid = x_grid + space_grid;

    }
    x_grid = 53;

    for (int j = 10; j < 20 ; j++) {

        text.setString("("+randomDrugs[j][1]+"x)");
        text.setPosition(x_grid, 308);
        game_window.draw(text); // draws drug
        x_grid = x_grid + space_grid;

    }

    x_grid = 53;

    for (int k = 20; k < 30 ; k++) {

        text.setString("("+randomDrugs[k][1]+"x)");
        text.setPosition(x_grid, 422);
        game_window.draw(text); // draws drug
        x_grid = x_grid + space_grid;

    }


}

void Engine::draw_background(){

    game_window.draw(bg);
}

void Engine::draw_main_assets(){
    draw_background();
    draw_drugs();
    draw_text();
    draw_amount();
    if(wow_i == 0){
        allow_color_change = false;
        wow_i++;
    }
    
}

void Engine::create_main(){

    main_window.create(VideoMode(1280, 720), "Main", Style::Close 	);
    main_window.setFramerateLimit(30);
   

}

void Engine::create_History_window(){


    history_window.create(VideoMode(960, 640), "History", Style::Close 	);
    history_window.setFramerateLimit(30);


}

void Engine::create_selector(){

    lvl_window.create(VideoMode(1280, 720), "Level", Style::Close 	);
    lvl_window.setFramerateLimit(30);
    lvl_window.draw(lvl);

}

void Engine::create_game_window(){                                          //game asli ejra mishe

    resolution = Vector2f(1044, 560);
    game_window.create(VideoMode(resolution.x, resolution.y), "Game", Style::Default);
    game_window.setFramerateLimit(FPS);

}

void Engine::create_end_game(){

    score_window.create(VideoMode(960, 640), "Score", Style::Close 	);
    score_window.setFramerateLimit(30);



}

void Engine::check_drugs(int arg){

    auto start = high_resolution_clock::now();                                     // start time

    if(arg==1)
        helper.setString("Please enter the amount");
    if(arg==2)
        helper.setString("Please enter the shelf number");
    Event event{};
    string temp_answer;
    for (asked; asked < 10; asked++) {
        
        draw_main_assets();
        ask.setString(drugNeeded[asked][0] + " : ");
        game_window.draw(helper);

        game_window.draw(ask);
        trigger = true;
        game_window.display();
        while (trigger) {
            while (game_window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    trigger = false;
                    asked = 11;
                    game_window.close();
                    quit_flag = true;
                }
                if(event.type == Event::TextEntered) {
                    if(event.text.unicode < 58 && event.text.unicode > 47) {
                        temp_answer += char((event.text.unicode));
                        answer.setString(temp_answer);
                    }
                    if(event.text.unicode == 13){
                        final_answer = temp_answer;
                        temp_answer.clear();
                        trigger = false;
                        break;

                    }
                    if(event.text.unicode == 27){
                        trigger = false;
                        asked = 11;
                        game_window.close();
                        quit_flag = true;
                    }
                }


            }
        }

        ofstream history;                                               // file name

        history.open("../headers/information.txt", ios::app);           // open file app mod

        auto stop = high_resolution_clock::now();

        auto duration = (duration_cast<std::chrono::microseconds>(stop - start)) / 1000000;

        float time_duration = duration.count();

        
        
        compare_drugs(final_answer,asked,arg,difficulty, time_duration);
        time_duration = 0;
        game_window.clear();
    }
}

void Engine::compare_drugs(string user_answer,int asked ,int arg,int level ,float duration )  {

    if(user_answer == drugNeeded[asked][arg]){
    score += 10;
        if (level == 6)
        {
            if (duration < 15)
            {
                score += 20;
            }
            else if (duration < 20)
            {
                score += 5;
            }
        }
        if (level == 10)
        {
            if (duration < 20)
            {
                score += 20;
            }
            else if (duration < 25)
            {
                score += 5;
            }
        }
        if (level == 15)
        {
            if (duration < 30)
            {
                score += 25;
            }
            else if (duration < 50)
            {
                score += 15;
            }
        }
    }
    timed = duration;

}


void Engine::save_info(){

    ofstream history;                                               // file name

    history.open("../headers/information.txt", ios::app);           // open file app mod

    history << "time spent : " << timed << "s"<< setw(17) << "\t";

    history << "Score : " << score << setw(15) << endl;

    history.close();

}
void Engine::read()
{

ifstream input("../headers/Information.txt");

    historyx.setFont(font_arl);
    historyx.setCharacterSize(30);
    historyx.setFillColor(Color::White);
    historyx.setPosition(50,120);

    while (getline(input, frint)){
        
    historyx.setString(frint);
    
    }



}

void Engine::run() {

    while(running) {

        create_main();

        // Main loop - Runs until the game_window is closed
        while (main_window.isOpen()) { //main menu
            main_window.clear();
            main_window.draw(main);
            main_window.draw(play);
            main_input();
            main_window.display();
        }

        lvl_window.display();
        while (lvl_window.isOpen()) { //select lvl
            lvl_input();
        }

        while (game_window.isOpen()) {
            game_window.clear();
            game_input();
            if(quit_flag) {
                game_window.close();
                break;
            }
            draw_main_assets();
            check_drugs(1);
            if(quit_flag) {
                game_window.close();
                break;
            }
            asked = 0;
            check_drugs(2);
            if(quit_flag) {
                game_window.close();
                break;
            }

            save_info();

            cout << score;
            game_window.display();
            game_window.close();
            create_end_game();

        } //game window

        running = false;

        while (history_window.isOpen())
        {
            history_window.clear();
            history_window.draw(history_bg);
            //read();
            history_window.draw(historyx);
            history_input();
            history_window.display();   
        }

        while (score_window.isOpen()) {
            score_window.clear();
            score_window.draw(score_bg);
            user_score.setString("YOUR SCORE IS : "+to_string(score));
            score_window.draw(user_score);
            score_window.display();
            score_input();
        }
        asked = 0;

    }
}

void Engine::main_input() {
    Event event{};

    while (main_window.pollEvent(event)) {
        // Window closed
        if (event.type == Event::Closed) {
            main_window.close();
        }

        // Handle Keyboard Input
        if (event.type == Event::KeyPressed) {
            // Quit
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                main_window.close();
            }
        }
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                Vector2i mouse_pos = Mouse::getPosition(main_window); // window is a sf::Window
                if(mouse_pos.x>463 && mouse_pos.x<815 && mouse_pos.y>236 && mouse_pos.y<333){ //start button
                    create_selector();
                    main_window.close();
                }
                else if(mouse_pos.x>470 && mouse_pos.x<813 && mouse_pos.y>365 && mouse_pos.y<461){      //match_history

                    
                    create_History_window();
                    read();
                    main_window.close();
                    
                }
                else if(mouse_pos.x>467 && mouse_pos.x<813 && mouse_pos.y>495 && mouse_pos.y<592){ //quit
                    game_window.close();
                    main_window.close();
                }
                else if(mouse_pos.x>54 && mouse_pos.x<120 && mouse_pos.y>638 && mouse_pos.y<680){ //umute
                    if(play.getTexture() == &texture_mute){
                        play.setTexture(texture_unmute);
                    }
                    else if(play.getTexture() == &texture_unmute){
                        play.setTexture(texture_mute);
                    }

                }
            }
        }
    }
}

void Engine::lvl_input(){
    Event event{};

    while (lvl_window.pollEvent(event)) {
        // Window closed
        if (event.type == Event::Closed) {
            lvl_window.close();
        }
        // Handle Keyboard Input
        if (event.type == Event::KeyPressed) {
            // Quit
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                lvl_window.close();
            }
        }
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                Vector2i mouse_pos = Mouse::getPosition(lvl_window); // window is a sf::Window
                if(mouse_pos.x>463 && mouse_pos.x<815 && mouse_pos.y>236 && mouse_pos.y<333){ //start button
                    difficulty = 6;
                    lvl_window.close();
                    create_game_window();

                }
                else if(mouse_pos.x>470 && mouse_pos.x<813 && mouse_pos.y>365 && mouse_pos.y<461){
                    difficulty = 10;
                    lvl_window.close();
                    create_game_window();
                }
                else if(mouse_pos.x>467 && mouse_pos.x<813 && mouse_pos.y>495 && mouse_pos.y<592){ //quit
                    difficulty = 15;
                    lvl_window.close();
                    create_game_window();
                }
            }
        }
    }

}

void Engine::game_input() {
    Event event{};
    while (game_window.pollEvent(event)) {
        // Window closed
        if (event.type == Event::Closed) {//
            game_window.close();
            quit_flag = true;
        }

        // Handle Keyboard Input
        if (event.type == Event::KeyPressed) {
            // Quit
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                game_window.close();
                quit_flag = true;
            }
        }
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                Vector2i mouse_pos = Mouse::getPosition(game_window); // window is a sf::Window
                cout << mouse_pos.x << "---" << mouse_pos.y << endl;
            }
        }

    }
}




void Engine::history_input(){
    Event event{};
    while (history_window.pollEvent(event))
    {
        if (event.type == Event::Closed) {//
            history_window.close();
            quit_flag = true;
        }


        if (event.type == Event::KeyPressed) {
            // Quit
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                history_window.close();
            }

        }

        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                Vector2i mouse_pos = Mouse::getPosition(history_window); // window is a sf::Window
                
                if(mouse_pos.x>473 && mouse_pos.x<674 && mouse_pos.y>503 && mouse_pos.y<552){ //main menu
                    history_window.close();
                    
                    running = true;
                }
                //cout << mouse_pos.x << "---" << mouse_pos.y << endl;
            }
        }

    }
    



}
void Engine::score_input(){

    Event event{};
    while (score_window.pollEvent(event)) {
        // Window closed
        if (event.type == Event::Closed) {
            score_window.close();
        }

        // Handle Keyboard Input
        if (event.type == Event::KeyPressed) {
            // Quit
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                score_window.close();
            }
        }
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                Vector2i mouse_pos = Mouse::getPosition(score_window); // window is a sf::Window
                if(mouse_pos.x>320 && mouse_pos.x<640 && mouse_pos.y>282 && mouse_pos.y<351){ //save button
                   //save score to save file
                }
                else if(mouse_pos.x>323 && mouse_pos.x<643 && mouse_pos.y>401 && mouse_pos.y<474){ //main menu
                    score_window.close();
                    running = true;
                }
                cout << mouse_pos.x << "---" << mouse_pos.y << endl;
            }
        }

    }


}