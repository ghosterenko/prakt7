#include <iostream>
#include <conio.h>
#include <Windows.h>
    
struct Node {
public:
    char value;
    Node* next;

    Node() : value('o'), next(nullptr) {}
};
class Snake {
public:
    Node* head = nullptr;
    int size = 0;
    int x, y;

    void add() {
        Node* newN = new Node();
        if (head == nullptr) 
            head = newN;
        else
            head->next = newN;

        size++;
    }

    void display() {
        Node* node = head;
        while (node != nullptr)
        {
            node->value;
            node = node->next;
        }
    }
    Node* node() {
        if (head != nullptr)
            return head;
    }

};

class Field {
public:
    Snake snake;
    const static int width = 20;
    const static int height = 10;
    char field[height][width];

    void StartGame() {
        srand(time(NULL));
        Node* node = snake.node();
        snake.add();
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
                field[i][j] = '-';
            field[i][0] = '\n';
        }
        snake.x = height / 2;
        snake.y = width / 2;
        field[snake.x][snake.y] = node->value;
    }
    void display() {
        Node* node = snake.node();
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                std::cout << field[i][j];

        field[snake.x][snake.y] = node->value;
    }
    
};

struct Food
{
    int x, y;
    Food(int X, int Y) : x(X), y(Y) {}
};

int main()
{
    setlocale(LC_ALL, "ru");
    Snake snake = Snake();
    Field f = Field();
    f.snake = snake;
    f.StartGame();
    f.display();
    while (true) {
        system("cls");
        f.display();
        if (_kbhit()) {
            char key = _getch();
            switch (key)
            {
            case 'w' : case 'W': f.field[snake.x][snake.y--] = snake.node()->value; f.field[snake.x][snake.y] = '-'; break;
            case 'a' : case 'A': f.field[snake.x--][snake.y] = snake.node()->value; f.field[snake.x][snake.y] = '-'; break;
            case 's' : case 'S': f.field[snake.x][snake.y++] = snake.node()->value; f.field[snake.x][snake.y] = '-'; break;
            case 'd' : case 'D': f.field[snake.x++][snake.y] = snake.node()->value; f.field[snake.x][snake.y] = '-'; break;
            default:
                break;
            }
        }
    }
    return 0;
}
