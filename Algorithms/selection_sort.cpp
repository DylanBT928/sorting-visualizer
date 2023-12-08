#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

struct data
{
	int height;
	int xpos;
} line[100];

int main()
{
	RenderWindow window;
	window.create(VideoMode(800, 500), "Selection Sort");
	window.setPosition(Vector2i(500, 200));
	
	RectangleShape rectangle(Vector2f(120.f, 50.f));
	rectangle.setFillColor(Color::White);
	std::vector<int> values;
	srand(time(NULL));

	while (window.isOpen())
	{
		Event event;
		window.clear(Color::Black);
		srand(time(NULL));

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

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