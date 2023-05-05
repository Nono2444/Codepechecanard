#include <stdio.h>
#include <allegro.h>

typedef struct canard{
    BITMAP* file;  //sprite
    int x, y;  //coordonnées du coin supérieur gauche
    int depx, depy;  //deplacement
    int posprex, posprey ;  //position précedente
    int tx, ty;  //taille de l'acteur

}t_canard;



int contact(t_canard *canard, BITMAP *bmp, int couleur)
{
  int ncontact;
  int xb, yb;
  ncontact=0;
  for (yb=0; yb<canard->ty;yb++){
      if (getpixel(bmp, canard->x, canard->y+yb)== couleur)
          ncontact++;
      if (getpixel(bmp, canard->x+canard->tx, canard->y+yb)== couleur)
          ncontact++;
  }
    for (xb=0; xb<canard->tx;xb++){
        if (getpixel(bmp, canard->x+xb, canard->y)== couleur)
            ncontact++;
        if (getpixel(bmp, canard->x+xb, canard->y+canard->ty)== couleur)
            ncontact++;
    }
    return ncontact;
}

void versouris(t_canard *canard){
    canard->depx=mouse_x - (canard->x + canard->tx/2);
    canard->depy=mouse_y - (canard->y + canard->ty/2);

    if (canard->depx>5) canard->depx=5;
    if (canard->depx<-5) canard->depx=-5;
    if (canard->depy>5) canard->depy=5;
    if (canard->depy<-5) canard->depy=-5;


}


void initialisation_allegro();


int main() {

    t_canard *canard;
    BITMAP *page;
    BITMAP *decor;
    BITMAP *murs;
    int compteur=0;

    initialisation_allegro();

    show_mouse(screen);

    page = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(page);
    decor = load_bitmap("pechecanard.bmp", NULL);
    murs = load_bitmap("collisioncanard.bmp", NULL);

    canard = (t_canard*) malloc(1 * sizeof(t_canard));
    canard->tx = 69; canard->ty = 75;
    canard->x = 300; canard->y = 60;
    canard->depx = 0; canard->depy = 0;
    canard->file = load_bitmap("spritecanard.bmp", NULL);

    int mousex_prec = mouse_x;
    int mousey_prec = mouse_y;

    while (!key[KEY_ESC]) {

        textprintf_ex(decor, font,30, 30, makecol(0, 0, 0), -1, "Score %d",compteur);

        blit(decor, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        masked_blit(canard->file, page, 0, 0, canard->x, canard->y, canard->tx, canard->ty); // page

        int mousex_diff = mouse_x - mousex_prec;
        int mousey_diff = mouse_y - mousey_prec;

        if (mouse_b & 1) {
            // Effacer l'ancienne position du sprite
            masked_blit(canard->file, page, canard->x, canard->y, canard->x, canard->y, canard->tx, canard->ty);

            canard->x += mousex_diff;
            canard->y += mousey_diff;
        }

        if (contact(canard, murs, makecol(255, 0, 0))) {  // collision lorsqu'on saisit le canard
            canard->x -= mousex_diff;
            canard->y -= mousey_diff;
        }

        mousex_prec = mouse_x;
        mousey_prec = mouse_y;


if (contact(canard, murs, makecol(255,255,0)))
{
 compteur++;

}
        blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }

    destroy_bitmap(canard->file);
    destroy_bitmap(decor);
    destroy_bitmap(murs);
    destroy_bitmap(page);
    free(canard);

    allegro_exit();

    return 0;
}
END_OF_MAIN();



void initialisation_allegro()
{
    allegro_init(); // appel obligatoire (var.globales, recup. infos syst�me ...)
    install_keyboard(); //pour utiliser le clavier
    install_mouse(); //pour utiliser la souris
    //pour choisir la profondeur de couleurs (8,16,24 ou 32 bits)
    set_color_depth(desktop_color_depth()); //ici�: identique � celle du bureau

    //s�lection du mode graphique
    // avec choix d'un driver+mode+r�solution de l'�cran
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    show_mouse(screen);
}