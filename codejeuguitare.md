# Codepechecanard
#include <allegro.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void initialisation_allegro();

int main()
{
    initialisation_allegro();
    srand(time(NULL));

    //BUFFER
    BITMAP* buffer;
    BITMAP* backs = load_bitmap("backstage.bmp",NULL);
    buffer = create_bitmap(500,600);

    //rayon
    int rayon = 30;

    //DEPLACEMENT
    int depy = 4;

    //SCORE TEMPS
    int temps = 0;
    int t = 1;
    int score1 = 0;
    int score2 = 0;

    //CLIQUE ACCELERATION
    int clic = 1;

    // POSITION CERCLES
    int posx1 = 100;
    int posx2 = 200;
    int posx3 = 300;
    int posx4 = 400;

    int posy1[4];
    int posy2[4];
    int posy3[4];
    int posy4[4];

    //CLIQUE SANS RESTER APUYER
    int presse  = 0;

    for(int i = 0; i<4; i++) {
        posy1[i] = rand() % 1971 - 2000;
        posy2[i] = rand() % 1971 - 2000;
        posy3[i] = rand() % 1971 - 2000;
        posy4[i] = rand() % 1971 - 2000;
    }

    int temp = 0;





    while (!key[KEY_SPACE]){
        //BUFFER
        clear_to_color(buffer, makecol(255,0,0));

        blit(backs,buffer,0,0,0,0,SCREEN_W,SCREEN_H);




        //CORDE
        vline(buffer,100,0,550, makecol(255,255,255));
        vline(buffer,200,0,550, makecol(255,255,255));
        vline(buffer,300,0,550, makecol(255,255,255));
        vline(buffer,400,0,550, makecol(255,255,255));
        //POINT
        circlefill(buffer,100,550,rayon, makecol(255,0,0));
        circlefill(buffer,200,550,rayon, makecol(255,255,0));
        circlefill(buffer,300,550,rayon, makecol(0,0,255));
        circlefill(buffer,400,550,rayon, makecol(255,0,225));
        //BOUTON
        circlefill(buffer,100,550,25, makecol(255,50,50));
        circlefill(buffer,200,550,25, makecol(200,200,100));
        circlefill(buffer,300,550,25, makecol(50,50,255));
        circlefill(buffer,400,550,25, makecol(255,100,225));

        //CERCLE
        for(int i = 0; i<4; i++){
            circlefill(buffer,posx1,posy1[i],rayon, makecol(255,80,80));
            circlefill(buffer,posx2,posy2[i],rayon, makecol(200,200,50));
            circlefill(buffer,posx3,posy3[i],rayon, makecol(40,20,220));
            circlefill(buffer,posx4,posy4[i],rayon, makecol(200,85,200));
        }

        //TEMPS
        textprintf_ex(buffer,font,220,30, makecol(0,0,0), makecol(255,255,255),"TEMPS: %d",temps);

        //DEPLACEMENT
        for(int i = 0; i<4; i++){
            posy1[i] = posy1[i] + depy;
            posy2[i] = posy2[i] + depy;
            posy3[i] = posy3[i] + depy;
            posy4[i] = posy4[i] + depy;
        }



        //TOUCHAGE DES RONDS
        for(int i = 0; i<4; i++) {
            //L1
            if (key[KEY_Q] && posy1[i] >= 500 && posy1[i] <= 600 && !presse) {
                posy1[i] = rand() % 1971 - 2000;
                clic++;
                presse = 1;
            }
            //L2
            if (key[KEY_W] && posy2[i] >= 500 && posy2[i] <= 600 && !presse) {
                posy2[i] = rand() % 1971 - 2000;
                clic++;
                presse = 1;
            }
            //L3
            if (key[KEY_E] && posy3[i] >= 500 && posy3[i] <= 600 && !presse) {
                posy3[i] = rand() % 1971 - 2000;
                clic++;
                presse = 1;
            }
            //L4
            if (key[KEY_R] && posy4[i] >= 500 && posy4[i] <= 600 && !presse) {
                posy4[i] = rand() % 1971 - 2000;
                clic++;
                presse = 1;
            }
        }
        presse = 0;

        //PERTE DE LA PARTIE
        for(int i = 0;i<4;i++){
            if((posy1[i] > 630 || posy2[i] > 630 || posy3[i] > 630 || posy4[i] > 630)) {
                temp=1;
                score1 = temps;
                t = -10000000;
                clear(buffer);
                textprintf_ex(buffer, font, 140, 300, makecol(255, 255, 255), -1, "VOUS AVEZ TENU %d SECONDES",score1);
                textprintf_ex(buffer, font, 125, 310, makecol(255, 255, 255), -1, "CLIQUER SUR ESPACE POUR J2");
            }
        }

        //ACCELERATION
        if(clic % 13 == 0 && !presse){
            depy = depy + 1;
            clic = 1;
            presse = 1;
        }
        presse = 0;



        //GESTION DU TEMPS
        t = t+1;
        if(t%26 == 0)
            temps++;
        //DOUBLE BUFFER
        blit(buffer,screen,0,0,150,0,SCREEN_W,SCREEN_H);
        //ACTUALISATION
        rest(20);
    }


    for(int i = 0; i<4; i++) {
        posy1[i] = rand() % 1971 - 2000;
        posy2[i] = rand() % 1971 - 2000;
        posy3[i] = rand() % 1971 - 2000;
        posy4[i] = rand() % 1971 - 2000;
    }
    temps = 0;
    depy = 4;



    while(!key[KEY_ESC]){
        //BUFFER
        clear_to_color(buffer, makecol(255,0,0));
        blit(backs,buffer,0,0,0,0,SCREEN_W,SCREEN_H);




        //CORDE
        vline(buffer,100,0,550, makecol(255,255,255));
        vline(buffer,200,0,550, makecol(255,255,255));
        vline(buffer,300,0,550, makecol(255,255,255));
        vline(buffer,400,0,550, makecol(255,255,255));
        //POINT
        circlefill(buffer,100,550,rayon, makecol(255,0,0));
        circlefill(buffer,200,550,rayon, makecol(255,255,0));
        circlefill(buffer,300,550,rayon, makecol(0,0,255));
        circlefill(buffer,400,550,rayon, makecol(255,0,225));
        //BOUTON
        circlefill(buffer,100,550,25, makecol(255,50,50));
        circlefill(buffer,200,550,25, makecol(200,200,100));
        circlefill(buffer,300,550,25, makecol(50,50,255));
        circlefill(buffer,400,550,25, makecol(255,100,225));

        //CERCLE
        for(int i = 0; i<4; i++){
            circlefill(buffer,posx1,posy1[i],rayon, makecol(255,80,80));
            circlefill(buffer,posx2,posy2[i],rayon, makecol(200,200,50));
            circlefill(buffer,posx3,posy3[i],rayon, makecol(40,20,220));
            circlefill(buffer,posx4,posy4[i],rayon, makecol(200,85,200));
        }

        //TEMPS
        textprintf_ex(buffer,font,220,30, makecol(0,0,0), makecol(255,255,255),"TEMPS: %d",temps);

        //DEPLACEMENT
        for(int i = 0; i<4; i++){
            posy1[i] = posy1[i] + depy;
            posy2[i] = posy2[i] + depy;
            posy3[i] = posy3[i] + depy;
            posy4[i] = posy4[i] + depy;
        }



        //TOUCHAGE DES RONDS
        for(int i = 0; i<4; i++) {
            //L1
            if (key[KEY_Q] && posy1[i] >= 500 && posy1[i] <= 600 && !presse) {
                posy1[i] = rand() % 1971 - 2000;
                clic++;
                presse = 1;
            }
            //L2
            if (key[KEY_W] && posy2[i] >= 500 && posy2[i] <= 600 && !presse) {
                posy2[i] = rand() % 1971 - 2000;
                clic++;
                presse = 1;
            }
            //L3
            if (key[KEY_E] && posy3[i] >= 500 && posy3[i] <= 600 && !presse) {
                posy3[i] = rand() % 1971 - 2000;
                clic++;
                presse = 1;
            }
            //L4
            if (key[KEY_R] && posy4[i] >= 500 && posy4[i] <= 600 && !presse) {
                posy4[i] = rand() % 1971 - 2000;
                clic++;
                presse = 1;
            }
        }
        presse = 0;

        //PERTE DE LA PARTIE
        for(int i = 0;i<4;i++){
            if((posy1[i] > 630 || posy2[i] > 630 || posy3[i] > 630 || posy4[i] > 630)) {
                temp=1;
                score2 = temps;
                t = -10000000;
                clear(buffer);
                textprintf_ex(buffer, font, 140, 300, makecol(255, 255, 255), -1, "VOUS AVEZ TENU %d SECONDES",score2);
                textprintf_ex(buffer, font, 125, 320, makecol(255, 255, 255), -1, "CLIQUER SUR ESC POUR QUITTER");
                if(score1>score2)
                    textprintf_ex(buffer, font, 125, 310, makecol(255, 255, 255), -1, "VICTOIRE DU JOUEUR NUMERO 1");
                if(score1<score2)
                    textprintf_ex(buffer, font, 125, 310, makecol(255, 255, 255), -1, "VICTOIRE DU JOUEUR NUMERO 2");
            }
        }

        //ACCELERATION
        if(clic % 13 == 0 && !presse){
            depy = depy + 1;
            clic = 1;
            presse = 1;
        }
        presse = 0;



        //GESTION DU TEMPS
        t = t+1;
        if(t%26 == 0)
            temps++;
        //DOUBLE BUFFER
        blit(buffer,screen,0,0,150,0,SCREEN_W,SCREEN_H);
        //ACTUALISATION
        rest(20);
    }

    allegro_exit();
    return 0;
}END_OF_MAIN();



void initialisation_allegro(){
    allegro_init(); // appel obligatoire (var.globales, recup. infos syst�me ...)
    install_keyboard(); //pour utiliser le clavier
    install_mouse(); //pour utiliser la souris
    //pour choisir la profondeur de couleurs (8,16,24 ou 32 bits)
    set_color_depth(desktop_color_depth()); //ici: identique a celle du bureau

    //selection du mode graphique
    // avec choix d'un driver+mode+resolution de l'ecran
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    //pour voir le curseur souris
    show_mouse(screen);
}


