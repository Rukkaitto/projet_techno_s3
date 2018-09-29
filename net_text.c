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
    display_game(_game);
    display_game_info(_game);
}