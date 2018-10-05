#include "game.h"
#include "game_io.h"
#include "stdio.h"
#include "stdlib.h"

void display_piece(piece p, direction d){
    switch(p){
        case EMPTY: 
            printf("  ");
            break;
        case LEAF: 
            switch(d){
                case N: printf("^ "); break;
                case E: printf("> "); break;
                case S: printf("v "); break;
                case W: printf("< "); break;
            } break;
        case SEGMENT: 
            switch(d){
                case N: printf("| "); break;
                case E: printf("- "); break;
                case S: printf("| "); break;
                case W: printf("- "); break;
            } break;
        case CORNER: 
            switch(d){
                case N: printf("└ "); break;
                case E: printf("┌ "); break;
                case S: printf("┐ "); break;
                case W: printf("┘ "); break;
            } break;
        case TEE: 
            switch(d){
                case N: printf("┴ "); break;
                case E: printf("├ "); break;
                case S: printf("┬ "); break;
                case W: printf("┤ "); break;
            } break;
    }
}

void display_game(game g){
    int width = game_width(g);
    int height = game_height(g);
    for(int y = height-1; y >= 0; y--){ //affiche la grille avec une origine (0,0) en bas à gauche
        for(int x = 0; x < width; x++){
            display_piece(get_piece(g,x,y), get_current_dir(g,x,y));
        }
        printf("\n");
    }
}
void display_game_info(game g){
    printf("Game dimensions are %dx%d.\n", game_width(g), game_height(g));
}


game default_game(){
    piece pieces[] = {  0,3,0,0,0,
                        0,3,3,2,1,
                        0,0,3,0,1,
                        3,3,3,3,3,
                        2,0,0,2,0};
                
    direction directions[] = {  E,W,S,E,S,
                                S,S,N,W,N,
                                E,N,W,W,W,
                                S,W,N,E,E,
                                W,N,W,N,S};
                                

    return new_game(pieces, directions);
}


int main() {
    game _game = default_game();
    while(!is_game_over(_game)){ //tant que la solution n'est pas trouvée :
        unsigned int x;
        unsigned int y;
        display_game(_game); //afficher la grille
        scanf("%u %u",&x,&y); //lire un coup sur l'entrée standard : (le format est le suivant : <x> <y>\n )
        if(x < game_width(_game) && y < game_height(_game)){ //si le coup est valide (les coordonnées sont correctes) alors
            rotate_piece_one(_game,x,y); //tourner la pièce de coordonnées (x,y) dans le sens horaire
        }
    }
    display_game(_game);
    printf("You won !\n");
    delete_game(_game);
}