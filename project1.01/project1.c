#include <stdio.h>
#include <stdlib.h>
#include <Math.h>
#include <time.h>

#define HEIGHT 21
#define WIDTH 80

//the x and y coordinates for 
//any region generated
struct Region {

    int x_pos;
    int y_pos;
    int radius;
    int x_min;
    int x_max;
    int y_min;
    int y_max;

};

struct Region region;


//height and width of game board
char board[HEIGHT][WIDTH];

//functions:

//Creates the borders for the game
void generateBoard() {

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y > 0 && y < HEIGHT - 1 && x > 0 && x < WIDTH - 1) {
                board[y][x] = ' ';
            }
            else {
                board[y][x] = '%';
            }
        }
    }
}

//generate roads
void generateRoad() {

    //pick random point from the border as exit
    int oldY;
    int oldX;

    int y_pos = rand() % 19 + 1;
    int x_pos = rand() % 78 + 1;

    int rand_num = rand() % 7 + 1;

    //for horizontal
    for (int x = 0; x < WIDTH; x++) {
        board[y_pos][x] = '#';
        if (x == x_pos) {
            oldY = y_pos;
            if (y_pos < HEIGHT / 2) {
                y_pos += rand_num;
                //creates pokeMart
            }
            else {
                y_pos -= rand_num;
            }
        }
    }

    //fill the gap in the road (will optimize later)
    if(y_pos>=oldY){
        for(int y = oldY; y <= y_pos; y++){
            board[y][x_pos]='#';
        }
    }
    else{
        for(int y=y_pos; y<=oldY; y++){
            board[y][x_pos]='#';
        }
    }

    //for vertical
    for (int y = 0; y < HEIGHT; y++) {
        board[y][x_pos] = '#';
        if (y == y_pos) {
            oldX = x_pos;
            if (x_pos < WIDTH / 2) {
                x_pos += rand_num;
                //creates pokeCenter
                board[y_pos-1][x_pos+6] = 'C';
                board[y_pos-1][x_pos+7] = 'C';
                board[y_pos-2][x_pos+6] = 'C';
                board[y_pos-2][x_pos+7] = 'C';
                //creates pokeMart
                board[y_pos-1][x_pos+4] = 'M';
                board[y_pos-1][x_pos+5] = 'M';
                board[y_pos-2][x_pos+4] = 'M';
                board[y_pos-2][x_pos+5] = 'M';
            }
            else {
                x_pos -= rand_num;
                //creates pokeCenter
                board[y_pos+1][x_pos+6] = 'C';
                board[y_pos+1][x_pos+7] = 'C';
                board[y_pos+2][x_pos+6] = 'C';
                board[y_pos+2][x_pos+7] = 'C';
                //creates pokeMart
                board[y_pos+1][x_pos+4] = 'M';
                board[y_pos+1][x_pos+5] = 'M';
                board[y_pos+2][x_pos+4] = 'M';
                board[y_pos+2][x_pos+5] = 'M';               
            }
        }
    }

    //fill the gap in the road (will optimize later)
    if(x_pos >= oldX){
        for(int x = oldX; x <= x_pos; x++){
            board[y_pos][x]='#';
        }
    }
    else{
        for(int x = x_pos; x <= oldX; x++){
            board[y_pos][x]='#';
        }
    }

    
    //for vertical
    // for (int y = 0; y < HEIGHT; y++) {
    //     board[y][x_pos] = '#';
    //     if (y == y_pos) {
    //         // if (x_pos + rand_num >= WIDTH - 1) {
    //         //     continue;
    //         // }
    //         // else {
    //         //     x_pos = x_pos + rand_num;
    //         // }
    //     }
    // }

}

//generate region
void generateRegion(char regionType) {

    region.y_pos = rand() % HEIGHT - 1;
    region.x_pos = rand() % WIDTH - 1;
    

    //extra check to make smaller boulders
    if(regionType=='%'){
        region.radius = rand() % 4;
    }
    else{
        region.radius = rand() % 15; //could be random generated
    }
    region.y_min = region.y_pos - region.radius;
    region.y_max = region.y_pos + region.radius;
    region.x_min = region.x_pos - region.radius;
    region.x_max = region.x_pos + region.radius;


    for(int y = region.y_max; y >= region.y_min; y--){
        for(int x = region.x_min; x <= region.x_max; x++){
            
            if (x > 0 && x < WIDTH-1 && y > 0 && y < HEIGHT-1) {

                //if border or road, ignore
                if(board[y][x] =='%' || board[y][x] =='#' || board[y][x] =='M' || board[y][x] =='C') continue;

                if((int) sqrt((x-region.x_pos)*(x-region.x_pos) + (y-region.y_pos)*(y-region.y_pos)) <= region.radius){
                    board[y][x] = regionType;
                }
            }

        }
    }

}

void fillVoid(char biomes[5]){

    int item_type = rand() % 5;

    for(int i=0; i<HEIGHT; i++){
        for(int j=0;j<WIDTH;j++){
            if(board[i][j]==' '){
                board[i][j] = biomes[item_type];
            }
        }
        item_type = rand() % 5;
    }


}

void printBoard() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv) {

    srand(time(NULL));

    char biomes[5] = {'%',':','.','^','~'};

    generateBoard();

    for(int i=0; i<5; i++){
        generateRegion(biomes[i]);
        generateRegion(biomes[i]);
        generateRegion(biomes[i]);
    }

    generateRoad();
    fillVoid(biomes);
    printBoard();

    return 0;
}
