#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace sf;

Event event;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
std::vector<int> values(SCREEN_WIDTH/4);
int iteration = 0;

void drawRay(RenderWindow &window, int pos, int height)
{
    RectangleShape ray(Vector2f(4, height));
    ray.setOrigin(Vector2f(0, height));
    ray.setPosition(pos*4, SCREEN_HEIGHT);
    if (iteration == pos)
        ray.setFillColor(Color::Red);
    window.draw(ray);
}

void sortingAlgorithm(int i)
{
    int buf = 0;
    if (values[i] > values[i + 1]) {
        buf = values[i];
        values[i] = values[i + 1];
        values[i + 1] = buf;
    }
}

int main()
{
    //Creates a window with specific dimensions
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sorting Visualizer");

    //Generates random height values
    srand(time(NULL));
    std::generate(values.begin(), values.end(), std::rand);

    for (int i = 0; i < values.size(); i++)
    {
        values[i] = values[i]/SCREEN_HEIGHT*5;
        std::cout<<values[i]<<'\n';
    }

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        window.clear();

        for (int i = 0; i < values.size(); i++)
            drawRay(window, i, values[i]);

        window.display();

        sortingAlgorithm(iteration);
        iteration++;
        if (iteration == values.size()-1)
            iteration = 0;
    }

    return 0;
}