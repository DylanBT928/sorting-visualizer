#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include "all_algorithms.hpp"

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

void sortingAlgorithm(int i, std::vector<int> &values)
{
    // Change class name to preferred algorithm
    selection_sort algorithm;
    algorithm.sort(i, values);
}

int main()
{
    // Creates a window with specific dimensions
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sorting Visualizer");

    // Generates random height values
    srand(time(NULL));
    std::generate(values.begin(), values.end(), std::rand);

    for (int i = 0; i < values.size(); i++)
        values[i] = values[i]/SCREEN_HEIGHT*5;

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

        sortingAlgorithm(iteration, values);
        iteration++;
        Sleep(1);
        if (iteration == values.size()-1)
            iteration = 0;
    }

    return 0;
}
