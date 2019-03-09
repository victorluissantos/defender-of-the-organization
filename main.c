/*Jogo Desenvolvido por: Victor Luis dos Santos RA:1090101-9
Jogo com objetivo de aprovação na materia de programação multiplataforma
*/
#include <allegro5/allegro5.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define max_x 800
#define max_y 600

int main()
{
    time_t current_time;
    BITMAP *buffer;
    BITMAP *fundo;
    BITMAP *bacteria_v;
    BITMAP *bacteria_l;
    BITMAP *virus;
    BITMAP *gblNinja;
    BITMAP *tiro;
    PALLETE pal;
   
    //inicialização da biblioteca
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, max_x, max_y, 0, 0);
    buffer = create_bitmap(max_x, max_y);
    //ALocando espaço em memoria.
    fundo = load_bitmap("Img\\BG.bmp", pal);
    bacteria_v = load_bitmap("Img\\bacteria_V.bmp", pal);
    bacteria_l = load_bitmap("Img\\bacteria_L.bmp", pal);
    virus = load_bitmap("Img\\virus_R.bmp", pal);
    gblNinja = load_bitmap("Img\\globuloninja.bmp", pal);
    tiro = load_bitmap("Img\\shot.bmp", pal);
     
    // variaveis do random da bacteria verde,laranja, e viruz
    int rBvX=20, rBvY=0, rBlX=120, rBlY=-0,rVrX=240, rVrY=-550, inNuPassV=0, inNuPassL=0,inNuPassR=0;
    int verificaBacteria_v=0,verificaBacteria_l=0, verificaVirus_r=0;
   
    //variaveis do personagem
    int gblX=380,gblY=430;
   
    //variaveis do tiro
    int tX=-50,tY=-50,tI=0;
   
    //variavel de controle de vidas
    int ind=0;
   
    //printf(i);
    int vidas=10,pontos=100,pontosA=0;
    while(!key[KEY_ESC])
    {
   //clear(screen);
   clear (buffer);
   //desenhando a imagem na tela
  
   draw_sprite(buffer, fundo, -200, 0);
// desenha as vidas
   textprintf_ex(buffer, font, 710, 10, makecol(255, 100, 200),
   -50, "Vidas: %d", vidas);
   textprintf_ex(buffer, font, 610, 30, makecol(255, 100, 200),
   -50, "Total de Pontos: %d", pontosA);
   textprintf_ex(buffer, font, 610, 10, makecol(255, 100, 200),
   -50, "Pontos: %d", pontos);
////////////////////////////////////////////////////////////////////////Moviemntos do teclado/////////////////////////

        if(key[KEY_LEFT])
        {
                         gblX=gblX-10;
        }
        if(key[KEY_RIGHT])
        {
                       gblX=gblX+10;
        }
        if(key[KEY_ENTER])
        {
                          if(tI==0)
                          {
                                   tX=gblX;
                                   tY=gblY;
                                   tI=1;        
                          }                                         
        }
        draw_sprite(buffer, gblNinja, gblX, gblY);
        draw_sprite(buffer, tiro, tX, tY);
//////////////////////////////////////////////////////////////////////////Randomiza e desenha a bacteria Verde ///////////////

   //Randome das posiçoes da batecria verde
   srand ( time(NULL) ); // planta o randomi
   if(rBvY > max_y-140 && verificaBacteria_v==0)
   {
           rBvY=0;
           verificaBacteria_v=1;
           pontos=pontos-10;
           pontosA=pontosA-10;
           ind=0;
   }
   if(verificaBacteria_v==1)
   {
   rBvX=rand()%500;
   if(inNuPassV == 0)
   {
   rBvX=(rBvX+rand()%500)/2;
   rBvX=rBvX+30;
   inNuPassV=3;
   }
   if(inNuPassV == 1)
   {
   rBvX=(rBvX+rand()%500)/2;
   rBvX=rBvX-30;
   inNuPassV=0;
   }
   if(inNuPassV==3)
   {
   inNuPassV=1;
   } 
   verificaBacteria_v=0;
   }
   rBvY=rBvY+1;
   //Desenha na tela a bacteria verde com posiçoes do random
  draw_sprite(buffer, bacteria_v, rBvX, rBvY);
 
//////////////////////////////////////////////////////////Fim da bacteria Verde
 
///////////////////////////////////////////////////////////Randomiza e Desenha a Bacteria Laranja//////////////////////////////


   //Randome das posiçoes da batecria laranja
   srand ( time(NULL) ); // planta o randomi
   if(rBlY > max_y-140 && verificaBacteria_l==0)
   {
           rBlY=0;
           verificaBacteria_l=1;
           pontos=pontos-20;
           pontosA=pontosA-20;
           ind=0;
   }
   if(verificaBacteria_l==1)
   {
   rBlX=rand()%500;
   if(inNuPassL == 0)
   {
   rBlX=(rBlX+rand()%500)/2;
   rBlX=rBlX+150;
   inNuPassL=3;
   }
   if(inNuPassL == 1)
   {
   rBlX=(rBlX+rand()%500)/2;
   rBlX=rBlX-150;
   inNuPassL=0;
   }
   if(inNuPassL==3)
   {
   inNuPassL=1;
   } 
   verificaBacteria_l=0;
   }
   rBlY=rBlY+2;
   //Desenha na tela a bacteria laranja com posiçoes do random
  draw_sprite(buffer, bacteria_l, rBlX, rBlY);

////////////////////////////////////////////////////////////////Fim da bacteria Laranja

//Randome das posiçoes da batecria verde
   srand ( time(NULL) ); // planta o randomi
   if(rVrY > max_y-140 && verificaVirus_r==0)
   {
           rVrY=-550;
           verificaVirus_r=1;
           pontos=pontos-50;
           pontosA=pontosA-50;
           ind=0;
   }
   if(verificaVirus_r==1)
   {
   rVrX=rand()%500;
   if(inNuPassR == 0)
   {
   rVrX=(rVrX+rand()%500)/2;
   rVrX=rVrX+40;
   inNuPassR=3;
   }
   if(inNuPassR == 1)
   {
   rVrX=(rVrX+rand()%500)/2;
   rVrX=rVrX-40;
   inNuPassR=0;
   }
   if(inNuPassR==3)
   {
   inNuPassR=1;
   } 
   verificaVirus_r=0;
   }
   rVrY=rVrY+3;
   //Desenha na tela a bacteria verde com posiçoes do random
  draw_sprite(buffer, virus, rVrX, rVrY);

/////////////////////////////////////////////////////////////////Fim do virus R

/////////////////////////////////////////Rota do tiro

  if(tI != 0)
  {
        if(tY<0)
        {
                tI=0;
        }
        // mata a bacteria verde
        if(tY < rBvY+20 && tX < rBvX+20 && tY > rBvY-20 && tX > rBvX-20)
        {
              rBvY=-70;
              tY=-50;
              tI=0;
              pontos=pontos+10;
              pontosA=pontosA+10;
        }
        //mata a bacteria Laranja
        if(tY < rBlY+20 && tX < rBlX+20 && tY > rBlY-20 && tX > rBlX-20)
        {
              rBlY=-70;
              tY=-50;
              tI=0;
              pontos=pontos+20;
              pontosA=pontosA+20;
        }
        //mata a Viruz roxo
        if(tY < rVrY+20 && tX < rVrX+20 && tY > rVrY-20 && tX > rVrX-20)
        {
              rVrY=-800;
              tY=-50;
              tI=0;
              pontos=pontos+50;
              pontosA=pontosA+50;
        }
        else
        tY=tY-10;
  }
/////////////////////////////////////////////////////////////////Fim do tiro
//////////////////////////////////////Inicio da contagem de vidas
 if(gblY < rBvY+20 && gblX < rBvX+20 && gblY > rBvY-20 && gblX > rBvX-20 && ind==0)
        {
        ind=1;
        vidas=vidas-1;
        }
        //mata a bacteria Laranja
        if(gblY < rBlY+20 && gblX < rBlX+20 && gblY > rBlY-20 && gblX > rBlX-20 && ind==0)
        {
        ind=1;
        vidas=vidas-1;
        }
        //mata a Viruz roxo
        if(gblY < rVrY+20 && gblX < rVrX+20 && gblY > rVrY-20 && gblX > rVrX-20 && ind==0)
        {
        ind=1;
        vidas=vidas-1;
        }

/////////////////////////////////////Inicio do controlador de troca dos creditos em vida
            if(pontos>200)
            {
                             pontos=0;
                             vidas=vidas+1;
            }
  ///////////////////////////////////////////////////////Inicipo do controlador para game Over.
  if(vidas < 0)
  {
 
  }
   // limpa tela.
  
   blit(buffer, screen, 0, 0, 0, 0, max_x, max_y);
  
   rest(20);
  
    }
    return 0;
}
END_OF_MAIN();
