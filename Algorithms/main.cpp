#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include "all_algorithms.hpp"

using namespace sf;

Event event;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;
std::vector<int> values(SCREEN_WIDTH/5);
int iteration = 0;

void drawRay(RenderWindow &window, int pos, int height)
{
    RectangleShape ray(Vector2f(4, height));
    ray.setOrigin(Vector2f(0, height));
    ray.setPosition(pos*5, SCREEN_HEIGHT);
    if (is_sorted(values.begin(), values.end()))
        ray.setFillColor(Color::Green);
    else
        if (iteration == pos)
            ray.setFillColor(Color::Red);
    window.draw(ray);
}

void sortingAlgorithm(int i, std::vector<int> &values)
{
    // Change class name to preferred algorithm
    bubble_sort algorithm;
    algorithm.sort(i, values);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

int main()
{
    // Creates a window with specific dimensions
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sorting Visualizer");

    // Generates random height values
    srand(time(NULL));
    std::generate(values.begin(), values.end(), std::rand);

    for (int i = 0; i < values.size(); i++)
        values[i] = values[i]/SCREEN_HEIGHT*6;

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
        if (iteration == values.size()-1)
            iteration = 0;
    }

    return 0;
}
