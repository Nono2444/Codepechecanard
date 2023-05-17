# Codepechecanard
#include <stdio.h>
#include <allegro.h>

void initialisation_allegro();

int main() {
    //INITIALISATION
    initialisation_allegro();

    //BUFFER
    BITMAP* buffer = create_bitmap(800,400);

    //BITMAP DECO
    BITMAP* her = load_bitmap("herbe.bmp",NULL);
    BITMAP* her2 = load_bitmap("herbe.bmp",NULL);
    BITMAP* nenu = load_bitmap("nenu.bmp", NULL);
    BITMAP* buche = load_bitmap("log.bmp",NULL);
    BITMAP* buche100 = load_bitmap("log100.bmp", NULL);
    BITMAP* buche150 = load_bitmap("log150.bmp", NULL);
    BITMAP* arbre = load_bitmap("arbre.bmp",NULL);
    BITMAP* frog = load_bitmap("frog.bmp", NULL);
    BITMAP* grenou = load_bitmap("grenou.bmp",NULL);
    BITMAP* river = load_bitmap("river.bmp",NULL);
    BITMAP* harbour = load_bitmap("harbour.bmp", NULL);
    BITMAP* horloge = create_bitmap(150,50);

    //TEMPS
    int temps = 0;
    int t = 0;
    int score1 = 0;
    int score2 = 0;

    //POSITION BUCHE
    //POSITION X
    int posx1 = 200;
    int posx2 = 650;
    int posx3 = 50;
    int posx4 = 350;
    int posx5 = 50;
    int posx6 = 450;
    int posx7 = 100;
    int posx8 = 350;
    int posx9 = 550;
    int posx10 = 0;
    int posx11 = 400;
    //POSITION Y
    int posyl1 = 0;
    int posyl2 = 50;
    int posyl3 = 150;
    int posyl4 = 200;
    int posyl5 = 300;

    //DEPLACEMENT
    int depx = 4;


    //POSITION GRENOUILLE
    int posgx = 400;
    int posgy = 350;

    //ETAT TOUCHE
    volatile int up_presse = 0;
    volatile int down_presse = 0;
    volatile int right_presse = 0;
    volatile int left_presse = 0;

    //ETAT GRENOUILLE SUR BUCHE
    int sur_buche = 0;

    //CHARGEMENT DEUXIEME PARTIE
    int swh = 0;





    //INTRODUCTION
    clear_to_color(screen, makecol (106, 222, 91));
    masked_blit(grenou,screen,0,0,0,350,grenou->w,grenou->h);
    draw_sprite(screen,river,650,0);
    textprintf_ex(screen,font,SCREEN_W/2 - 160,SCREEN_H/2, makecol(0,0,0),-1,"CLIQUEZ SUR UNE TOUCHE POUR COMMENCER LA PARTIE");
    readkey();





    while (!key[KEY_ESC]){
        //BUFFER
        clear_to_color(buffer, makecol(100,200,255));
        clear_to_color(horloge, makecol(100,255,100));




        //DEPART
        blit(harbour,buffer,0,0,400,350,50,50);
        blit(harbour,buffer,0,0,350,350,50,50);
        blit(harbour,buffer,0,0,450,350,50,50);

        //AFFICHAGE DES BUCHES
        draw_sprite(buffer,buche100,posx1,posyl1);
        draw_sprite(buffer,buche100,posx2,posyl1);
        //L2
        draw_sprite(buffer,buche150,posx3,posyl2);
        draw_sprite(buffer,buche,posx4,posyl2);
        //L3
        draw_sprite(buffer,buche150,posx5,posyl3);
        draw_sprite(buffer,buche100,posx6,posyl3);
        //L4
        draw_sprite(buffer,buche150,posx7,posyl4);
        draw_sprite(buffer,buche100,posx8,posyl4);
        draw_sprite(buffer,buche150,posx9,posyl4);
        //L5
        draw_sprite(buffer,buche150,posx10,posyl5);
        draw_sprite(buffer,buche150,posx11,posyl5);




        //DEPLACEMENT BUCHE
        //L1
        posx1 = posx1 + depx;
        posx2 = posx2 + depx;
        //L2
        posx3 = posx3 - depx;
        posx4 = posx4 - depx;
        //L3
        posx5 = posx5 + depx;
        posx6 = posx6 + depx;
        //L4
        posx7 = posx7 - depx;
        posx8 = posx8 - depx;
        posx9 = posx9 - depx;
        //L5
        posx10 = posx10 + depx;
        posx11 = posx11 + depx;





        //CONTROLE BORDURE
        if(posx1 > SCREEN_W)
            posx1 = -100;
        if(posx2 > SCREEN_W)
            posx2 = -100;
        //L2
        if(posx3 + 150<0)
            posx3 = SCREEN_W + 50;
        if(posx4 + 200<0)
            posx4 = SCREEN_W;
        //L3
        if(posx5 > SCREEN_W)
            posx5 = -150;
        if(posx6 > SCREEN_W)
            posx6 = -150;
        //L4
        if(posx7+150 < 0)
            posx7 = SCREEN_W;
        if(posx8+100 < 0)
            posx8 = SCREEN_W + 50;
        if(posx9+150<0)
            posx9 = SCREEN_W;
        //L5
        if(posx10>SCREEN_W)
            posx10 = -150;
        if(posx11>SCREEN_W)
            posx11 = -150;






        //AFFICHAGE DES NENUPHARS
        draw_sprite(buffer,nenu,250,100);
        draw_sprite(buffer,nenu,550,100);
        draw_sprite(buffer,nenu,150,250);
        draw_sprite(buffer,nenu,400,250);
        draw_sprite(buffer,nenu,650,250);

        //AFFICHAGE HERBE
        blit(her,screen,0,0,0,0,800,100);
        hline(her,0,99,800, makecol(0,0,0));
        blit(her2,screen,0,0,0,500,800,100);
        hline(her2,0,0,800, makecol(0,0,0));
        //AFFICHAGE DECO
        draw_sprite(her2,arbre,25,0);
        draw_sprite(her2,arbre,-30,0);
        draw_sprite(her2,arbre,80,0);

        draw_sprite(her2,arbre,730,0);
        draw_sprite(her2,arbre,620,0);
        draw_sprite(her2,arbre,675,0);


        //GRENOUILLE
        draw_sprite(buffer,frog,posgx,posgy);

        //VERIFICATION SUR BUCHE
        //L5
        if((posgy == posyl5) && (posgx > posx10 - 20) && (posgx < posx10 + 130)) {
            posgx = posgx + depx;
            sur_buche = 0;
        }
        else if((posgy == posyl5) && (posgx > posx11 - 20) && (posgx < posx11 + 130)) {
            posgx = posgx + depx;
            sur_buche = 0;
        }
        //L4
        else if((posgy == posyl4) && (posgx > posx9 - 20) && (posgx < posx9 + 130)) {
            posgx = posgx - depx;
            sur_buche = 0;
        }
        else if((posgy == posyl4) && (posgx > posx8 - 15) && (posgx < posx8 + 85)) {
            posgx = posgx - depx;
            sur_buche = 0;
        }
        else if((posgy == posyl4) && (posgx > posx7 - 20) && (posgx < posx7 + 130)) {
            posgx = posgx - depx;
            sur_buche = 0;
        }
        //L3
        else if((posgy == posyl3) && (posgx > posx6-15) && (posgx < posx6 + 85)) {
            posgx = posgx + depx;
            sur_buche = 0;
        }
        else if((posgy == posyl3) && (posgx > posx5-20) && (posgx < posx5 + 130)) {
            posgx = posgx + depx;
            sur_buche = 0;
        }
        //L2
        else if((posgy == posyl2) && (posgx > posx4 - 30) && (posgx < posx4 + 170)) {
            posgx = posgx - depx;
            sur_buche = 0;
        }
        else if((posgy == posyl2) && (posgx > posx3 - 20) && (posgx < posx3 + 130)) {
            posgx = posgx - depx;
            sur_buche = 0;
        }
        //L1
        else if((posgy == posyl1) && (posgx > posx2 - 15) && (posgx < posx2 + 85)) {
            posgx = posgx + depx;
            sur_buche = 0;
        }
        else if((posgy == posyl1) && (posgx > posx1 - 15) && (posgx < posx1 + 85)) {
            posgx = posgx + depx;
            sur_buche = 0;
        }
        //LES 3 NENU DU BAS
        else if((posgy == 250) && posgx >= 130 && posgx <= 190)
            sur_buche = 0;
        else if((posgy == 250) && posgx >= 380 && posgx <= 440)
            sur_buche = 0;
        else if((posgy == 250) && posgx >= 620 && posgx <= 690)
            sur_buche = 0;
        //LES 2 NENU DU HAUT
        else if((posgy == 100) && posgx >= 230 && posgx <= 290)
            sur_buche = 0;
        else if((posgy == 100) && posgx >= 530 && posgx <= 590)
            sur_buche = 0;
        //SUR LE DEPART
        else if(posgy == 350 && posgx >= 330&& posgx <= 470)
            sur_buche = 0;
        //SI LA GRENOUILLE N'EST SUR RIEN
        else if(posgy == -50)
            sur_buche = 0;
        else
            sur_buche = 1;

        //ETAT SUR EAU OU NON JOUEUR 1
        if (sur_buche == 1 && swh == 0){
            posgx = 0;
            posgy = 350;
            clear_to_color(buffer, makecol(100,200,255));
            textprintf_ex(buffer,font,300,200, makecol(0,0,0), -1,"VOUS ETES TOMBE DANS L'EAU");
            textprintf_ex(buffer,font,280,210, makecol(0,0,0),-1,"CLIQUER SUR ECHAP POUR QUITTER");
            textprintf_ex(buffer,font,300,220, makecol(0,0,0),-1,"DONC VICTOIRE DU JOUEUR 2");
            temps = 0;
        }
        //ETAT SUR EAU OU NON JOUEUR 2
        if (sur_buche == 1 && swh == 1){
            posgx = 0;
            posgy = 350;
            clear_to_color(buffer, makecol(100,200,255));
            textprintf_ex(buffer,font,300,200, makecol(0,0,0), -1,"VOUS ETES TOMBE DANS L'EAU");
            textprintf_ex(buffer,font,280,210, makecol(0,0,0),-1,"CLIQUER SUR ECHAP POUR QUITTER");
            textprintf_ex(buffer,font,300,220, makecol(0,0,0),-1,"DONC VICTOIRE DU JOUEUR 1");
            temps = 0;
        }

        //ARRIVER JOUEUR 1
        if(posgy == -50 && swh == 0){
            score1 = temps;
            t = -1000000000;
            textprintf_ex(buffer,font,200,200, makecol(0,0,0), makecol(255,255,255),"FELICITATION VOUS AVEZ TRAVERSE LA RIVIERE EN %d SECONDES", score1);
            textprintf_ex(buffer,font,210,208, makecol(0,0,0), makecol(255,255,255),"APPUYER SUR ESPACE POUR LANCER LA PARTIE DU JOUEUR 2");
            if(key[KEY_SPACE]){
                posgx = 400;
                posgy = 350;
                swh = 1;
                temps = 0;
            }
        }

        if(posgy == -50 && swh == 1){
            score2 = temps;
            t = -100000000;
            clear_to_color(buffer, makecol(100,200,255));
            textprintf_ex(buffer,font,200,190, makecol(0,0,0), makecol(255,255,255),"VOUS AVEZ TRAVERSE LA RIVIERE EN %d SECONDES", score2);
            textprintf_ex(buffer,font,200,210, makecol(0,0,0), makecol(255,255,255),"APPUYER SUR ECHAP QUITTER");
            if(score1 > score2)
                textprintf_ex(buffer,font,200,200, makecol(0,0,0), makecol(255,255,255),"VICTOIRE DU JOUEUR 2");
            else if(score2 > score1)
                    textprintf_ex(buffer,font,200,200, makecol(0,0,0), makecol(255,255,255),"VICTOIRE DU JOUEUR 1");
        }

        //DEPLACEMENT GRENOUILLE
        //VERS LE HAUT
        if(key[KEY_UP] && !up_presse){
            posgy = posgy - 50;
            up_presse = 1;
        }
        if(!key[KEY_UP])
            up_presse = 0;
        //VERS LE BAS
        if(key[KEY_DOWN] && !down_presse){
            posgy = posgy + 50;
            down_presse = 1;
        }
        if(!key[KEY_DOWN])
            down_presse = 0;
        //VERS LA DROITE
        if(key[KEY_RIGHT] && !right_presse){
            posgx = posgx + 50;
            right_presse = 1;
        }
        if(!key[KEY_RIGHT])
            right_presse = 0;
        //VERS LA GAUCHE
        if(key[KEY_LEFT] && !left_presse){
            posgx = posgx - 50;
            left_presse = 1;
        }
        if(!key[KEY_LEFT])
            left_presse = 0;

        //GESTION DU TEMPS
        t = t+1;
        if(t%26 == 0)
            temps++;

        textprintf_ex(horloge,font,40,20, makecol(0,0,0),-1,"TEMPS: %d", temps);




        //DOUBLE BUFFER
        blit(buffer,screen,0,0,0,100,800,400);
        blit(horloge,her,0,0,345,25,150,50);

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

