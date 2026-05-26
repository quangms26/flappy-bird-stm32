#include "main.h"

#include "game.h"
#include "bird.h"
#include "pipe.h"
#include "buzzer.h"

#include <stdio.h>

extern ucg_t ucg;


typedef enum
{
    LEVEL_EASY,
    LEVEL_HARD

} Level_t;


typedef enum
{
    GAME_MENU,
    GAME_PLAYING,
    GAME_OVER

} GameState_t;


GameState_t gameState = GAME_MENU;

Level_t level = LEVEL_EASY;

int score = 0;



void Game_Reset(void);

void Draw_Menu(void);

void Draw_Game(void);

void Draw_GameOver(void);

void Check_Collision(void);

void LED_GameOverBlink(void);



// INIT


void Game_Init(void)
{
    Bird_Init();

    Pipe_Init();
}




// UPDATE

void Game_Update(void)
{

    switch(gameState)
    {


        // MENU


        case GAME_MENU:

            Draw_Menu();

            if(GPIO_ReadInputDataBit(GPIOC,
                                     GPIO_Pin_0) == 0)
            {
                delay_ms(200);

                Game_Reset();

                gameState = GAME_PLAYING;
            }


            if(GPIO_ReadInputDataBit(GPIOC,
                                     GPIO_Pin_1) == 0)
            {
                delay_ms(200);

                if(level == LEVEL_EASY)
                {
                    level = LEVEL_HARD;
                }
                else
                {
                    level = LEVEL_EASY;
                }
            }

            break;




        // PLAYING


        case GAME_PLAYING:

            if(GPIO_ReadInputDataBit(GPIOC,
                                     GPIO_Pin_0) == 0)
            {
                Bird_Jump();

                Buzzer_Beep();
            }


            Bird_Update();

            Pipe_Update();

            Check_Collision();

            Draw_Game();

            delay_ms(30);

            break;


        // GAME OVER

        case GAME_OVER:

            Draw_GameOver();

            LED_GameOverBlink();

            if(GPIO_ReadInputDataBit(GPIOC,
                                     GPIO_Pin_0) == 0)
            {
                delay_ms(300);

                Game_Reset();

                gameState = GAME_PLAYING;
            }

            break;
    }
}


// RESET

void Game_Reset(void)
{
    Bird_Init();

    Pipe_Init();

    score = 0;

    if(level == LEVEL_EASY)
    {
        pipeSpeed = 2;
    }
    else
    {
        pipeSpeed = 4;
    }
}


// MENU

void Draw_Menu(void)
{
    ucg_ClearScreen(&ucg);

    ucg_SetFont(&ucg,
                ucg_font_6x10_tf);

    ucg_DrawString(&ucg,
                   10,
                   20,
                   0,
                   "FLAPPY BIRD");


    if(level == LEVEL_EASY)
    {
        ucg_DrawString(&ucg,
                       10,
                       50,
                       0,
                       "> EASY");

        ucg_DrawString(&ucg,
                       10,
                       70,
                       0,
                       "  HARD");
    }
    else
    {
        ucg_DrawString(&ucg,
                       10,
                       50,
                       0,
                       "  EASY");

        ucg_DrawString(&ucg,
                       10,
                       70,
                       0,
                       "> HARD");
    }
}


// DRAW GAME

void Draw_Game(void)
{
    char text[20];

    ucg_ClearScreen(&ucg);


    // TOP PIPE

    ucg_DrawBox(&ucg,
                pipe.x,
                0,
                10,
                pipe.gapY);


    // BOTTOM PIPE

    ucg_DrawBox(&ucg,
                pipe.x,
                pipe.gapY + pipeGapSize,
                10,
                160);


    // BIRD

    ucg_DrawBox(&ucg,
                30,
                (int)bird.y,
                8,
                8);


    // SCORE

    sprintf(text,
            "S:%d",
            score);

    ucg_SetFont(&ucg,
                ucg_font_6x10_tf);

    ucg_DrawString(&ucg,
                   0,
                   10,
                   0,
                   text);
}



// COLLISION


void Check_Collision(void)
{

    // SCREEN

    if(bird.y <= 0 || bird.y >= 150)
    {
        gameState = GAME_OVER;
    }


    // PIPE

    if(pipe.x < 38 && pipe.x > 20)
    {
        if(bird.y < pipe.gapY ||
           bird.y + 8 > pipe.gapY + pipeGapSize)
        {
            gameState = GAME_OVER;
        }
    }
}


// GAME OVER

void Draw_GameOver(void)
{
    char text[20];

    ucg_ClearScreen(&ucg);

    ucg_SetFont(&ucg,
                ucg_font_6x10_tf);

    ucg_DrawString(&ucg,
                   20,
                   40,
                   0,
                   "GAME OVER");

    sprintf(text,
            "SCORE:%d",
            score);

    ucg_DrawString(&ucg,
                   20,
                   70,
                   0,
                   text);
}



// LED BLINK

void LED_GameOverBlink(void)
{
    GPIO_ToggleBits(GPIOA,
                    GPIO_Pin_5);

    delay_ms(100);
}
