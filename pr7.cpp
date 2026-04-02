#include <iostream>
#include <conio.h>
#include <Windows.h>
    
struct Node {
public:
    char value;
    Node* next;

    Node(char Value) : value(Value), next(nullptr) {}
};
class Snake {
public:
    Node* head = nullptr;
    int size = 0;
    int x, y;
    
    void add(char value) {
        Node* newN = new Node(value);
        if (head == nullptr) {
            head = newN;
        }
        else {
            head->next = newN;
        }
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
        snake.add('o');
        snake.add('o');
        snake.add('o');
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                field[i][j] = '-';
            }
            field[i][0] = '\n';
        }
        snake.x = height / 2;
        snake.y = width / 2;
        field[snake.x][snake.y] = node->value;
        node = node->next;
    }
    void display() {
        Node* node = snake.node();
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                std::cout << field[i][j];
            }
        }
        field[snake.x][snake.y] = node->value;
    }
    
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
            if (key == 'w')
                snake.x--;
        }
        Sleep(500);
    }

    return 0;
}
