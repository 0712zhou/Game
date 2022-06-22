//
// Created by xiaozhou on 2022/6/22.
//
#include "game.h"
//对棋盘进行初始化，以空格的形式输出
void InitBoard(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

//创建并打印棋盘
void DiplayBoard(char board[ROW][COL],int row,int col)
{
    int i = 0;

    for(i=0; i<row; i++)
    {
        int j = 0;
        for(j=0; j<col; j++)
        {
            printf(" %c ",board[i][j]);
            if(j<col-1)
            printf("|");
        }
        printf("\n");
        if(i<row-1)
        {
            for(j=0; j<col; j++)
            {
                printf("---");
                if(j<col-1)
                    printf("|");
            }
            printf("\n");
        }
    }
}

//玩家下棋
void PlayerMove(char board[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;
    printf("玩家选择位置>:");
    while(1)
    {
        scanf("%d %d", &x, &y);
        if (x>=1 && x<=row && y>=1 && y<=col)
        {
            if(board[x-1][y-1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
                printf("该位置已被占用，请重新输入>:");

        } else
            printf("输入超出范围，请重新输入>:");
    }
}

//电脑下棋
void ComputerMove(char board[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;
    printf("电脑选择位置>:\n");
    while(1)
    {
        x = rand() % row;
        y = rand() % col;
        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

//判断棋盘是否下满
int IfFull(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j = 0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

//状态返回函数
char Iswin(char board[ROW][COL],int row,int col)
{
    int i = 0;
    //行判断
    for(i=0; i<row; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];
        }
    }
    //列判断
    for(i=0; i<col; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
        {
            return board[1][i];
        }
    }
    //对角线判断
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    //判断是否平局
    if(IfFull(board,ROW,COL) == 1)
    {
        return 'Q';
    }
    return 'C';

}
