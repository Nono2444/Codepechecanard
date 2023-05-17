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

    // initialisation de la variable pour la souris
    int mouseX, mouseY;

    //BUFFER
    BITMAP* buffer;
    buffer = create_bitmap(780,490);


    //AFFICHAGE
    bool clic = false;
    bool clic2 = false;
    bool clic3 = false;
    bool clic4 = false;
    int score1 = 0;
    int score2 = 0;
    int temps = 0;
    int t = 0;

    //BALLON
    int rayon = 30;
    int posx1, posy1;
    int posx2, posy2;
    int posx3, posy3;
    int posx4, posy4;


    posx1 = rand()%721 + 40;
    posx2 = rand()%721 + 40;
    posx3 = rand()%721 + 40;
    posx4 = rand()%721 + 40;


    posy1 = rand()%431 + 30;
    posy2 = rand()%431 + 30;
    posy3 = rand()%431 + 30;
    posy4 = rand()%431 + 30;


    int couleur1 = makecol(255,0,0);
    int couleur2 = makecol(0,255,0);
    int couleur3 = makecol(0,0,255);
    int couleur4 = makecol(255,150,0);


    //DEPLACEMENT BALLON
    int depx1;
    int depy1;
    int depx2;
    int depy2;
    int depx3;
    int depy3;
    int depx4;
    int depy4;




    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////JOUEUR 1/////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    clear_to_color(screen, makecol(255,255,255));
    textprintf_ex(screen,font,10,10, makecol(0,0,0),-1,"REGLE: A tour de role cliquer le plus rapidement possible sur tous les ballons en mouvement.");
    textprintf_ex(screen,font,65,20, makecol(0,0,0),-1,"Celui qui realise le meilleur temps est vainqueur du jeu.");
    textprintf_ex(screen,font,65,30, makecol(0,0,0),-1,"La partie demarre directement pour le joueur1 lorsque vous cliquer.");
    textprintf_ex(screen,font,65,40, makecol(255,0,0),-1,"ATTENTION ! APPUYEZ SUR R SI PROBLEME D'INITIALISATION");
    hline(screen,0,50,SCREEN_W, makecol(0,0,0));
    textprintf_ex(screen,font,10,60, makecol(255,0,0),-1,"JOUEUR 1: %d", score1);
    textprintf_ex(screen,font,10,70, makecol(0,0,255),-1,"JOUEUR 2: %d", score2);
    textprintf_ex(screen,font,SCREEN_W/2 - 20,65, makecol(0,0,0),-1,"TEMPS:");
    rect(screen,10,100,SCREEN_W - 10, SCREEN_H - 10, makecol(0,0,0));
    textprintf_ex(screen,font,SCREEN_W/2 - 180,SCREEN_H/2, makecol(0,0,0),-1,"CLIQUER SUR UNE TOUCHE POUR DEBUTER LA PARTIE !");
    readkey();
    rectfill(screen,SCREEN_W/2 - 180,SCREEN_H/2,SCREEN_W/2 + 200,SCREEN_H/2 +30, makecol(255,255,255));

    //DEPLACEMENT DANS TOUT LES SENS POUR LES BALLONS
    depx1 = rand()%21 - 10;
    depy1 = rand()%21 - 10;
    depx2 = rand()%21 - 10;
    depy2 = rand()%21 - 10;
    depx3 = rand()%21 - 10;
    depy3 = rand()%21 - 10;
    depx4 = rand()%21 - 10;
    depy4 = rand()%21 - 10;





    while(!key[KEY_ESC]){
        clear_to_color(buffer, makecol(255,255,255));
        textprintf_ex(screen,font,SCREEN_W/2 + 40, 65, makecol(255,255,255),-1,"%d", temps);


        //PROBLEME APUIE SUR R
        if(key[KEY_R]){
            posx1 = rand()%721 + 40;
            posx2 = rand()%721 + 40;
            posx3 = rand()%721 + 40;
            posx4 = rand()%721 + 40;


            posy1 = rand()%431 + 30;
            posy2 = rand()%431 + 30;
            posy3 = rand()%431 + 30;
            posy4 = rand()%431 + 30;
            temps = 0;
        }



        //BLOQUAGE DE BORDURE POUR LES BALLONS
        if( (posx1-rayon<40 && depx1<0) || ( posx1+rayon>750 && depx1>0) )
            depx1 = -depx1;
        if( (posy1-rayon < 30 && depy1<0) || (posy1+rayon>460 && depy1>0) )
            depy1 = -depy1;
        if( (posx2-rayon<40 && depx2<0) || ( posx2+rayon>750 && depx2>0) )
            depx2 = -depx2;
        if( (posy2-rayon < 30 && depy2<0) || (posy2+rayon>460 && depy2>0) )
            depy2 = -depy2;
        if( (posx3-rayon<40 && depx3<0) || ( posx3+rayon>750 && depx3>0) )
            depx3 = -depx3;
        if( (posy3-rayon < 30 && depy3<0) || (posy3+rayon>460 && depy3>0) )
            depy3 = -depy3;
        if( (posx4-rayon<40 && depx4<0) || ( posx4+rayon>750 && depx4>0) )
            depx4 = -depx4;
        if( (posy4-rayon < 30 && depy4<0) || (posy4+rayon>460 && depy4>0) )
            depy4 = -depy4;

        //COLISION
        int dis = sqrt((posx2-posx1)*(posx2-posx1) + (posy2-posy1)*(posy2-posy1));
        if(dis < 60){
            depx1 = -depx1;
            depy1 = -depy1;
            depx2 = -depx2;
            depy2 = -depy2;
        }
        int dis2 = sqrt((posx3-posx1)*(posx3-posx1) + (posy3-posy1)*(posy3-posy1));
        if(dis2 < 60){
            depx1 = -depx1;
            depy1 = -depy1;
            depx3 = -depx3;
            depy3 = -depy3;
        }
        int dis3 = sqrt((posx3-posx2)*(posx3-posx2) + (posy3-posy2)*(posy3-posy2));
        if(dis3 < 60){
            depx2 = -depx2;
            depy2 = -depy2;
            depx3 = -depx3;
            depy3 = -depy3;
        }
        int dis4 = sqrt((posx4-posx1)*(posx4-posx1) + (posy4-posy1)*(posy4-posy1));
        if(dis4 < 60){
            depx1 = -depx1;
            depy1 = -depy1;
            depx4 = -depx4;
            depy4 = -depy4;
        }
        int dis5 = sqrt((posx4-posx2)*(posx4-posx2) + (posy4-posy2)*(posy4-posy2));
        if(dis5 < 60){
            depx2 = -depx2;
            depy2 = -depy2;
            depx4 = -depx4;
            depy4 = -depy4;
        }
        int dis6 = sqrt((posx4-posx3)*(posx4-posx3) + (posy4-posy3)*(posy4-posy3));
        if(dis6 < 60){
            depx3 = -depx3;
            depy3 = -depy3;
            depx4 = -depx4;
            depy4 = -depy4;
        }



        //CLIQUE SUR LES BALLONS
        mouseX = mouse_x - 10;
        mouseY = mouse_y - 100;
        if (mouse_b & 1 && (mouseX - posx1) * (mouseX - posx1) + (mouseY - posy1) * (mouseY - posy1) <= rayon * rayon) {
            couleur1 = makecol(255,255,255);// sort de la boucle si le clic gauche de la souris est détecté dans le cercle
            clic = true;
        }
        if (mouse_b & 1 && (mouseX - posx2) * (mouseX - posx2) + (mouseY - posy2) * (mouseY - posy2) <= rayon * rayon) {
            couleur2 = makecol(255,255,255);  // sort de la boucle si le clic gauche de la souris est détecté dans le cercle
            clic2 = true;
        }
        if (mouse_b & 1 && (mouseX - posx3) * (mouseX - posx3) + (mouseY - posy3) * (mouseY - posy3) <= rayon * rayon) {
            couleur3 = makecol(255,255,255);  // sort de la boucle si le clic gauche de la souris est détecté dans le cercle
            clic3 = true;
        }
        if (mouse_b & 1 && (mouseX - posx4) * (mouseX - posx4) + (mouseY - posy4) * (mouseY - posy4) <= rayon * rayon) {
            couleur4 = makecol(255,255,255);  // sort de la boucle si le clic gauche de la souris est détecté dans le cercle
            clic4 = true;
        }


        //ACTUALISATION DES POSITIONS
        posx1 = posx1 + depx1;
        posy1 = posy1 + depy1;
        posx2 = posx2 + depx2;
        posy2 = posy2 + depy2;
        posx3 = posx3 + depx3;
        posy3 = posy3 + depy3;
        posx4 = posx4 + depx4;
        posy4 = posy4 + depy4;

        //AFFICHAGE DES CERCLES
        circlefill(buffer,posx1,posy1,rayon, couleur1);
        circlefill(buffer,posx2,posy2,rayon, couleur2);
        circlefill(buffer,posx3,posy3,rayon, couleur3);
        circlefill(buffer,posx4,posy4,rayon, couleur4);


        blit(buffer,screen,0,0,11,101,779,489);


        //TEMPS
        t = t +1;
        if(t%26 == 0) {
            temps++;
            depx1 = rand()%11 - 5;
            depy1 = rand()%11 - 5;
            depx2 = rand()%11 - 5;
            depy2 = rand()%11 - 5;
            depx3 = rand()%11 - 5;
            depy3 = rand()%11 - 5;
            depx4 = rand()%11 - 5;
            depy4 = rand()%11 - 5;
        }

        textprintf_ex(screen,font,SCREEN_W/2 + 40, 65, makecol(0,0,0),-1,"%d", temps);



        if(clic && clic2 && clic3 && clic4) {
            score1 = temps;
            temps = 0;
            break;
        }


        rest(20);
    }

    clear_to_color(screen, makecol(255,255,255));









    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////JOUEUR 2//////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //INTERFACE
    textprintf_ex(screen,font,SCREEN_W/2 - 130,SCREEN_H/2 - 50, makecol(0,0,0),-1,"TEMPS DU JOUEUR 1: %d secondes", score1);
    textprintf_ex(screen,font,SCREEN_W/2 - 220,SCREEN_H/2 + 50, makecol(0,0,0),-1,"CLIQUER SUR UNE TOUCHE POUR LANCER LA PARTIE DU JOUEUR 2");
    readkey();
    clear_to_color(screen, makecol(255,255,255));
    textprintf_ex(screen,font,10,10, makecol(0,0,0),-1,"REGLE: A tour de role cliquer le plus rapidement possible sur tous les ballons en mouvement.");
    textprintf_ex(screen,font,65,20, makecol(0,0,0),-1,"Celui qui realise le meilleur temps est vainqueur du jeu.");
    textprintf_ex(screen,font,65,30, makecol(0,0,0),-1,"La partie demarre directement pour le joueur2 lorsque vous cliquer.");
    textprintf_ex(screen,font,65,40, makecol(255,0,0),-1,"ATTENTION ! APPUYEZ SUR R SI PROBLEME D'INITIALISATION");
    hline(screen,0,50,SCREEN_W, makecol(0,0,0));
    textprintf_ex(screen,font,10,60, makecol(255,0,0),-1,"JOUEUR 1: %d", score1);
    textprintf_ex(screen,font,10,70, makecol(0,0,255),-1,"JOUEUR 2: %d", score2);
    textprintf_ex(screen,font,SCREEN_W/2 - 20,65, makecol(0,0,0),-1,"TEMPS:");
    rect(screen,10,100,SCREEN_W - 10, SCREEN_H - 10, makecol(0,0,0));
    textprintf_ex(screen,font,SCREEN_W/2 - 180,SCREEN_H/2, makecol(0,0,0),-1,"CLIQUER SUR UNE TOUCHE POUR DEBUTER LA PARTIE !");
    readkey();
    rectfill(screen,SCREEN_W/2 - 180,SCREEN_H/2,SCREEN_W/2 + 200,SCREEN_H/2 +30, makecol(255,255,255));

    //INITIALISATION POUR J2
    t = 0;
    temps = 0;
    clic = clic2 = clic3 = false;
    couleur1 = makecol(255,0,0);
    couleur2 = makecol(0,255,0);
    couleur3 = makecol(0,0,255);
    couleur4 = makecol(255,20,147);

    //PARTIE POUR J2
    while (!key[KEY_ESC]){
        clear_to_color(buffer, makecol(255,255,255));
        textprintf_ex(screen,font,SCREEN_W/2 + 40, 65, makecol(255,255,255),-1,"%d", temps);

        //PROBLEME  AFFICHAGE
        if(key[KEY_R]){
            posx1 = rand()%721 + 40;
            posx2 = rand()%721 + 40;
            posx3 = rand()%721 + 40;
            posx4 = rand()%721 + 40;


            posy1 = rand()%431 + 30;
            posy2 = rand()%431 + 30;
            posy3 = rand()%431 + 30;
            posy4 = rand()%431 + 30;
            temps = 0;
        }



        //BLOQUAGE DE BORDURE POUR LES BALLONS
        if( (posx1-rayon<40 && depx1<0) || ( posx1+rayon>750 && depx1>0) )
            depx1 = -depx1;
        if( (posy1-rayon < 30 && depy1<0) || (posy1+rayon>460 && depy1>0) )
            depy1 = -depy1;
        if( (posx2-rayon<40 && depx2<0) || ( posx2+rayon>750 && depx2>0) )
            depx2 = -depx2;
        if( (posy2-rayon < 30 && depy2<0) || (posy2+rayon>460 && depy2>0) )
            depy2 = -depy2;
        if( (posx3-rayon<40 && depx3<0) || ( posx3+rayon>750 && depx3>0) )
            depx3 = -depx3;
        if( (posy3-rayon < 30 && depy3<0) || (posy3+rayon>460 && depy3>0) )
            depy3 = -depy3;
        if( (posx4-rayon<40 && depx4<0) || ( posx4+rayon>750 && depx4>0) )
            depx4 = -depx4;
        if( (posy4-rayon < 30 && depy4<0) || (posy4+rayon>460 && depy4>0) )
            depy4 = -depy4;

        //COLISION
        int dis = sqrt((posx2-posx1)*(posx2-posx1) + (posy2-posy1)*(posy2-posy1));
        if(dis < 60){
            depx1 = -depx1;
            depy1 = -depy1;
            depx2 = -depx2;
            depy2 = -depy2;
        }
        int dis2 = sqrt((posx3-posx1)*(posx3-posx1) + (posy3-posy1)*(posy3-posy1));
        if(dis2 < 60){
            depx1 = -depx1;
            depy1 = -depy1;
            depx3 = -depx3;
            depy3 = -depy3;
        }
        int dis3 = sqrt((posx3-posx2)*(posx3-posx2) + (posy3-posy2)*(posy3-posy2));
        if(dis3 < 60){
            depx2 = -depx2;
            depy2 = -depy2;
            depx3 = -depx3;
            depy3 = -depy3;
        }
        int dis4 = sqrt((posx4-posx1)*(posx4-posx1) + (posy4-posy1)*(posy4-posy1));
        if(dis4 < 60){
            depx1 = -depx1;
            depy1 = -depy1;
            depx4 = -depx4;
            depy4 = -depy4;
        }
        int dis5 = sqrt((posx4-posx2)*(posx4-posx2) + (posy4-posy2)*(posy4-posy2));
        if(dis5 < 60){
            depx2 = -depx2;
            depy2 = -depy2;
            depx4 = -depx4;
            depy4 = -depy4;
        }
        int dis6 = sqrt((posx4-posx3)*(posx4-posx3) + (posy4-posy3)*(posy4-posy3));
        if(dis6 < 60){
            depx3 = -depx3;
            depy3 = -depy3;
            depx4 = -depx4;
            depy4 = -depy4;
        }


        //CLIQUE SUR LES BALLONS
        mouseX = mouse_x - 10;
        mouseY = mouse_y - 100;
        if (mouse_b & 1 && (mouseX - posx1) * (mouseX - posx1) + (mouseY - posy1) * (mouseY - posy1) <= rayon * rayon) {
            couleur1 = makecol(255,255,255);// sort de la boucle si le clic gauche de la souris est détecté dans le cercle
            clic = true;
        }
        if (mouse_b & 1 && (mouseX - posx2) * (mouseX - posx2) + (mouseY - posy2) * (mouseY - posy2) <= rayon * rayon) {
            couleur2 = makecol(255,255,255);  // sort de la boucle si le clic gauche de la souris est détecté dans le cercle
            clic2 = true;
        }
        if (mouse_b & 1 && (mouseX - posx3) * (mouseX - posx3) + (mouseY - posy3) * (mouseY - posy3) <= rayon * rayon) {
            couleur3 = makecol(255,255,255);  // sort de la boucle si le clic gauche de la souris est détecté dans le cercle
            clic3 = true;
        }
        if (mouse_b & 1 && (mouseX - posx4) * (mouseX - posx4) + (mouseY - posy4) * (mouseY - posy4) <= rayon * rayon) {
            couleur4 = makecol(255,255,255);  // sort de la boucle si le clic gauche de la souris est détecté dans le cercle
            clic4 = true;
        }


        //ACTUALISATION DES POSITIONS
        posx1 = posx1 + depx1;
        posy1 = posy1 + depy1;
        posx2 = posx2 + depx2;
        posy2 = posy2 + depy2;
        posx3 = posx3 + depx3;
        posy3 = posy3 + depy3;
        posx4 = posx4 + depx4;
        posy4 = posy4 + depy4;

        //AFFICHAGE DES CERCLES
        circlefill(buffer,posx1,posy1,rayon, couleur1);
        circlefill(buffer,posx2,posy2,rayon, couleur2);
        circlefill(buffer,posx3,posy3,rayon, couleur3);
        circlefill(buffer,posx4,posy4,rayon, couleur4);

        //BUFFER
        blit(buffer,screen,0,0,11,101,779,489);


        //TEMPS
        t = t +1;
        if(t%26 == 0) {
            temps++;
            depx1 = rand()%11 - 5;
            depy1 = rand()%11 - 5;
            depx2 = rand()%11 - 5;
            depy2 = rand()%11 - 5;
            depx3 = rand()%11 - 5;
            depy3 = rand()%11 - 5;
            depx4 = rand()%11 - 5;
            depy4 = rand()%11 - 5;
        }
        textprintf_ex(screen,font,SCREEN_W/2 + 40, 65, makecol(0,0,0),-1,"%d", temps);


        //CONDITION DE FIN DE PARTIE
        if(clic && clic2 && clic3 && clic4) {
            score2 = temps;
            break;
        }


        rest(20);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////ANNONCE DU VAINQUEUR///////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    clear_to_color(screen, makecol(255,255,255));
    if(score1 < score2){
        textprintf_ex(screen,font,SCREEN_W/2 - 100,SCREEN_H/2, makecol(0,0,0),-1,"JOUEUR 1 VAINQUEUR !");
        textprintf_ex(screen,font,SCREEN_W/2 - 130,SCREEN_H/2 + 10, makecol(0,0,0),-1,"CLIQUER SUR ESC POUR QUITTER");
    } else if (score2 < score1) {
        textprintf_ex(screen, font, SCREEN_W / 2 - 100, SCREEN_H / 2, makecol(0, 0, 0), -1, "JOUEUR 2 VAINQUEUR !");
        textprintf_ex(screen, font, SCREEN_W / 2 - 130, SCREEN_H / 2 + 10, makecol(0, 0, 0), -1,"CLIQUER SUR ESC POUR QUITTER");
    }

    while (!key[KEY_ESC]){

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

