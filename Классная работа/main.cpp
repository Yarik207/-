
#include "TXLib.h"
struct mainMan
{
int x;
int y;
int w;
int h;
HDC pic;
};

void DrawHero (mainMan hero)
{
    Win32::TransparentBlt(txDC(), hero.x, hero.y, hero.w, hero.h, hero.pic, 0, 0, 35, 40, TX_WHITE);
}


int main()
{
txCreateWindow(950,850);

txDisableAutoPause();
txTextCursor(false);

char str[100];

 int Level=1;

 int OldheroX;
 int OldheroY;

 bool ReturnBack;


HDC coin= txLoadImage("картинки/лабиринты/coin.bmp");

HDC labStart= txLoadImage("картинки/лабиринты/mini.bmp");

mainMan hero={13, 375, 35, 40, txLoadImage("картинки/лабиринты/перс.bmp")};



string PAGE = "Menu";


while(true)
{
txClear();
txBegin();

if(PAGE == "Menu")
{


 txSetColor(TX_WHITE,5);
 txSetFillColor(TX_BLACK);


 txRectangle(410,35,545,90);
 txDrawText(410,35,545,90,"Начать/Продолжить");

 if(txMouseX() >= 410 && txMouseY() >= 35 &&
    txMouseX() <= 545 && txMouseY() <= 90 &&
    txMouseButtons() == 1)
  {
    PAGE = "Game";
  }


  txRectangle(410,165,545,230);
 txDrawText(410,165,545,230,"Информация");

 if(txMouseX() >= 410 && txMouseY() >= 165 &&
    txMouseX() <= 545 && txMouseY() <= 230 &&
    txMouseButtons() == 1)
 {
    PAGE = "Info";
 }

  txRectangle(405,790,545,845);
  txDrawText(405,790,545,845,"Выйти");

  if(txMouseX() >= 405 && txMouseY() >= 790 &&
     txMouseX() <= 545 && txMouseY() <= 845 &&
     txMouseButtons() == 1)
    {
     return 0;
    }
}

if(PAGE == "Info")
{
    txSetColor(TX_WHITE);
    txSetFillColor(TX_BLACK);
    txRectangle(0,0,950,850);
    txSelectFont("Times", 30);
    txDrawText(0,0,950,850,
                   "Об игре\n"
                  "\n"
                  "Лабиринт,главная цель выбраться,(желательно живым)\n"
                  "\n"
                  "Управление\n"
                  "\n"
                  "влево (A) вправо (D) вперед (W) назад (S)\n"
                  "\n"
                  "Пауза\n"
                  "\n"
                  "Esc\n"
                  "\n"
                  "Об авторах\n"
                  "\n"
                  "Ingenerka Game Studio\n");

    txRectangle(405,710,545,780);
    txDrawText(405,710,545,780,"Назад");

    if(txMouseX() >= 405 && txMouseY() >= 710 &&
    txMouseX() <= 545 && txMouseY() <= 780 &&
    txMouseButtons() == 1)
    {
        PAGE = "Menu";
    }
}

if(PAGE == "Game")
{
  if(GetAsyncKeyState(VK_ESCAPE))
   {
    PAGE = "Menu";
   }

txBitBlt(txDC(), 0, 0, 946, 847, labStart);
DrawHero (hero);

ReturnBack=false;
OldheroX=hero.x;
OldheroY=hero.y;

 if(GetAsyncKeyState('D'))
 {
 hero.x=hero.x+10;
 }

 if(GetAsyncKeyState('A'))
 {
 hero.x=hero.x-10;
 }


 if(GetAsyncKeyState('S'))
 {
 hero.y=hero.y+10;
 }

 if(GetAsyncKeyState('W'))
 {
 hero.y=hero.y-10;
 }

  for(int x=hero.x;x<hero.x+hero.w;x=x+5)
  {
    for(int y=hero.y;y<hero.y+hero.h;y=y+5)
    {
        if(txGetPixel(x,y) == RGB(0,0,0))
        {
            ReturnBack=true;
        }
    }
  }


    if(ReturnBack)
     {
      hero.x=OldheroX;
      hero.y=OldheroY;
     }

   if(txGetPixel(hero.x+hero.w,hero.y+hero.h) == RGB(70,70,70))
   {
    Level++;
    txSleep(2000);
   }



 if(Level==2 && txGetPixel(hero.x+hero.w,hero.y+hero.h) == RGB(70,70,70))
 {
  labStart = txLoadImage ("картинки/лабиринты/2 .bmp");
  hero.x=45;
  hero.y=840;
  hero.w=23;
  hero.h=26;
 }


 if(Level==3 && txGetPixel(hero.x+hero.w,hero.y+hero.h) == RGB(70,70,70))
 {
  labStart = txLoadImage ("картинки/лабиринты/3.bmp");

  hero.x=5;
  hero.y=365;
  hero.w=18;
  hero.h=20;
 }

  if(Level==4 && txGetPixel(hero.x+hero.w,hero.y+hero.h) == RGB(70,70,70))
 {
  labStart = txLoadImage ("картинки/лабиринты/4 финал.bmp");

  hero.x=45;
  hero.y=385;
  hero.w=9;
  hero.h=10;
 }

  if(txGetPixel(hero.x+hero.w,hero.y+hero.h) == RGB(127,127,127))
   {

    txSetColor(TX_WHITE);
    txSetFillColor(TX_BLACK);
    txRectangle(0,0,950,850);
    txSelectFont("Times", 30);
    txDrawText(0,0,950,850,
                   "Любопытство и чувство долга\n"
                  "\n"
                  "Вели тебя вперед\n"
                  "\n"
                  "ты выходишь из храма испытаний\n"
                  "\n"
                  "Новый спаситель земли\n"
                  "\n"
                  "Раздалось из толпы поселенцев\n"
                  "\n"
                  "Но справишься ли ты с этим прbзванием\n"
                  "\n"
                  "Узнаем в следующий раз\n"
                  "\n"
                  "Скоро увидимся с ухмылкой говорит раccказчик, закрывая книгу\n");

   }



txEnd();
}
txSleep(10);
}


txDeleteDC (labStart);

txDeleteDC (hero.pic);


txDeleteDC (coin);
    return 0;
    }

