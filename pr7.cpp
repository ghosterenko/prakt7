#include <iostream>

class Snake {
public:
    struct Node {
        char value;
        Node* next;
    
        Node(char Value) : value(Value), next(nullptr) {}
    };
    Node* head = nullptr;
    
    void add(char value) {
        Node* newN = new Node(value);
        if (head == nullptr)
            head = newN;

        head->next = newN;
    }

    char display() {
        Node* node = head;
        while (node != nullptr)
        {
            node->value;
            node = node->next;
        }
    }

};

class Field {
    int width = 20;
    int height = 10;
    char field[255];

public:
    void draw() {
        srand(time(NULL));

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                field[j] = '-';
            }
            field[i] = '\n';
        }
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                std::cout << field[j];
            }
        }
    }
    void drawSnake(Snake snake) {
        snake.add('0');
        snake.add('0');
        snake.add('0');

        snake.display();
    }
    
};

int main()
{
    Snake snake = Snake();
    Field f = Field();
    f.draw();
    f.drawSnake(snake);
}
