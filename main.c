#include"game.h"
//创建菜单menu
void menu()
{
    printf("**************************\n");
    printf("** 1、开始游戏  0、游戏结束 **\n");
    printf("**************************\n");
}

//创建游戏函数game
void game()
{
    char let = 0;
    //定义数组
    char Board[ROW][COL] = {0};
    //对棋盘进行初始化
    InitBoard(Board,ROW,COL);
    //对棋盘进行打印
    DiplayBoard(Board,ROW,COL);

    while(1) {
        //玩家下棋
        PlayerMove(Board, ROW, COL);
        DiplayBoard(Board, ROW, COL);

        //返回输赢状态：1、玩家赢返回‘*’ 2、电脑赢返回‘#’ 3、平局返回‘Q’ 4、没结束继续
        let = Iswin(Board,ROW,COL);
        if(let != 'C')
        {
            break;
        }

        //电脑下棋
        ComputerMove(Board,ROW,COL);
        DiplayBoard(Board, ROW, COL);
        if(let != 'C')
        {
            break;
        }
    }
    if(let == '*')
    {
        printf("玩家赢！\n");
    }
    else if(let == '#')
    {
        printf("电脑赢！\n");
    }
    else if(let == 'Q')
    {
        printf("平局！\n");
    }
}
int main() {
    system("chcp 65001");
    srand((unsigned int)time(NULL));
    int input = 0;
    do {
        menu();
        printf("请选择模式>:");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("游戏结束！\n");
                break;
            default:
                printf("输入有误，请重新输入>:");

        }

    }while(input);

    return 0;
}
