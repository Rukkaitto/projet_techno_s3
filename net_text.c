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

bool check_right_piece(game g, int x, int y){
    piece current_piece = get_piece(g,x,y);
    piece next_piece = get_piece(g,x+1,y);
    
}

game default_game(){

}


int main() {
    game _game = new_game_empty();
    set_piece(_game, 4, 4, TEE, S);
    set_piece(_game,0,1,CORNER,E);
    display_game(_game);
    display_game_info(_game);
}