#include "GameManager.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "util/TMXParser.h"

#include "InputManager.h"
#include "LogicManager.h"
#include "DrawManager.h"

#include "CONSTANTS.h"

namespace GameManager
{
    const int FPS = 60;

    ALLEGRO_EVENT_QUEUE* eventQueue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_DISPLAY* display;

    bool isRunning;

    void abortGame(const char* message)
    {
        printf("%s \n", message);
        exit(1);
    }    

    void init()
    {
        if (!al_init())
            abortGame("Failed to initialize allegro");

        if (!al_init_image_addon())
            abortGame("Failed to initialize image addon");

        //if(!al_init_font_addon())
        //    abortGame("Failed to initialize font addon");

        //if(!al_init_ttf_addon())
        //    abortGame("Failed to initialize ttf addon");

        if(!al_install_keyboard())
            abortGame("Failed to install keyboard");

        timer = al_create_timer(1.0 / FPS);
        if (!timer)
            abortGame("Failed to create timer");

        al_set_new_display_flags(ALLEGRO_WINDOWED);
        display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
        if (!display)
            abortGame("Failed to create display"); 

        eventQueue = al_create_event_queue();
        if (!eventQueue)
            abortGame("Failed to create event queue");
    
        al_register_event_source(eventQueue, al_get_keyboard_event_source());
        al_register_event_source(eventQueue, al_get_timer_event_source(timer)); 
        al_register_event_source(eventQueue, al_get_display_event_source(display));

        GameState::instance = new GameState();

        isRunning = true;
    }

    void loadGameData()
    {
        TMXParser tmxParser;
        tmxParser.parseTMXFile("res/StartTemple.tmx", GameState::instance);
    } 

    void gameLoop()
    {
        LogicManager logicManager;
        InputManager inputManager;
        DrawManager drawManager;
        bool redraw = true;
        al_start_timer(timer);

        while(isRunning)
        {
            ALLEGRO_EVENT event;
            al_wait_for_event(eventQueue, &event);

            if (event.type == ALLEGRO_EVENT_TIMER) 
            {
                redraw = true;
            }
            else if (event.type == ALLEGRO_EVENT_KEY_DOWN ||
                    event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ||
                    event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            {
                inputManager.Process(event, &logicManager);
            }
            else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                isRunning = false;
            }
            
            if (redraw && al_is_event_queue_empty(eventQueue))
            {
                redraw = false;
                al_clear_to_color(al_map_rgb(0, 0, 0));

                drawManager.draw();

                al_flip_display();
            }
        }
    }

    void shutdown()
    {
        if (timer)
            al_destroy_timer(timer);

        if (display)
            al_destroy_display(display);

        if (eventQueue)
            al_destroy_event_queue(eventQueue);
    }
}
