#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

int x,y,i,j,fruitx, fruity, flag;
int height=30, width=30, gameover, score;

void draw();
void setup();
void logic();
void input();

int main(){
    int m,n;
    setup();
    while(!gameover){
        draw();
        input();
        logic();
    }
    return 0;
}

void draw(){
    system("cls");
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i == 0 || i == width - 1 || j == 0 || j == height - 1){
                printf("#");
            }else{ 
                if (i == x && j == y) 
                    printf("0"); 
                else if (i == fruitx 
                         && j == fruity) 
                    printf("*"); 
                else
                    printf(" "); 
            } 
        }
        printf("\n");
    }
}

void setup(){
    gameover = 0;
    x = height / 2;
    y = width / 2;

    label1:
    fruitx = rand()%20;
    if(fruitx == 0)
    goto label1;

    label2:
    fruity = rand()%20;
    if(fruity == 0)
    goto label2;

    score = 0;
}

void input(){
    if(kbhit()){
        switch(getchar()){
            case 'a':
            flag = 1;
            break;
            case 's':
            flag = 2;
            break;
            case 'd':
            flag = 3;
            break;
            case 'w':
            flag = 4;
            break;
            case 'q':
            gameover = 1;
            break;
        }
    }
    printf("gameover? %d \n", gameover);
    printf("press q to quit");

}

void logic(){
    sleep(0.001);
    switch(flag){
        
        case 1:
        y--;
        break;

        case 2:
        x++;
        break;
        
        case 3:
        y++;
        break;
        
        case 4:
        x--;
        break;
        
        default:
        break; 
        
        gameover = 1;
        break;
    } if(x < 0 || x > height || y < 0 || y > width){
        gameover = 1;
        if(x==fruitx && y==fruity){
            
            label3:
            x=rand()%20;
            if(x==0)
            goto label3;

            label4:
            y=rand()%20;
            if(y==0)
            goto label4;

            score += 20;
        }
    }
}