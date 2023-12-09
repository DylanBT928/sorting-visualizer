#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

RenderWindow window;
RectangleShape rectangle(Vector2f(120.f, 50.f));
std::vector<int> values;
struct data { int height, xpos; } line[100];

bool isSorted(std::vector<int> val)
{
	for (int i = 0; i < val.size()-1; i++)
	{
		for (int j = 1; j < val.size(); j++)
		{
			if (val[i] > val[j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
    window.create(VideoMode(800, 500), "Selection Sort");
    window.setPosition(Vector2i(400, 200));

    rectangle.setFillColor(Color::White);
    srand(time(NULL));

    while (window.isOpen())
    {
        Event event;
        window.clear(Color::Black);
        srand(time(NULL));

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    window.close();
                    break;
            }
        }

        // Creates rectangles with randomized heights
        // Heights are stored in "values" vector
        for (int i = 0; i < 100; i++)
        {
            values.push_back(rand()%45+1);
            rectangle.setFillColor(Color::White);
            rectangle.setPosition(8+8*i, 500);
            rectangle.setSize(Vector2f(8, values[i]*10));
            rectangle.setRotation(180);
            window.draw(rectangle);
        }

        window.display();
    }

    return 0;
}