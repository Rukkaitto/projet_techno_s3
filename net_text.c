#include "game.h"
#include "game_io.h"
#include "stdio.h"
#include "stdlib.h"

void display_piece(piece p, direction d){
    if(p==EMPTY){
        printf("  ");
    }
    if(p==LEAF){
        if(d==N){
            printf("^ ");
        }
        if(d==E){
            printf("> ");
        }
        if(d==W){
            printf("< ");
        }
        if(d==S){
            printf("v ");
        }
        
    }
    if(p==SEGMENT){
        if(d==N){
            printf("| ");
        }
        if(d==E){
            printf("- ");
        }
        if(d==W){
            printf("- ");
        }
        if(d==S){
            printf("| ");
        }
    }
    if(p==CORNER){
        if(d==N){
            printf("└ ");
        }
        if(d==E){
            printf("┌ ");
        }
        if(d==W){
            printf("┘ ");
        }
        if(d==S){
            printf("┐ ");
        }
    }
    if(p==TEE){
        if(d==N){
            printf("┴ ");
        }
        if(d==E){
            printf("├ ");
        }
        if(d==W){
            printf("┤ ");
        }
        if(d==S){
            printf("┬ ");
        }
    }
}

void display_game(game g){
    int width = game_width(g);
    int height = game_height(g);
    for(int y = 0; y < height; y++){
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
    piece pieces[] = {  2,0,0,2,0,
                        3,3,3,3,3,
                        0,0,3,0,1,
                        0,3,3,2,1,
                        0,3,0,0,0};
    
    direction directions[] = {  W,N,W,N,S,
                                S,W,N,E,E,
                                E,N,W,W,W,
                                S,S,N,W,N,
                                E,W,S,E,S};
                                

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
            rotate_piece(_game,x,y,1); //tourner la pièce de coordonnées (x,y) dans le sens horaire
        }
    }
    display_game(_game);
    delete_game(_game);
}