#include <SFML/Graphics.hpp>
using namespace sf;

struct data
{
	int height;
	int xpos;
} line[100];

int main()
{
	RenderWindow window;
	window.create(VideoMode(800, 500), "Testing");
	window.setPosition(Vector2i(500, 200));
	
	RectangleShape rectangle(Vector2f(120.f, 50.f));
	rectangle.setFillColor(Color::White);

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
			rectangle.setFillColor(Color::White);
			rectangle.setPosition(8, 500);
			rectangle.setSize(Vector2f(8, 100)); //TODO: randomize the 100
			rectangle.setRotation(180);
			window.draw(rectangle);
		}
		window.display();
	}

	return 0;
}