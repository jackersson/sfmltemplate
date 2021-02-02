#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-activity", __VA_ARGS__))

int main(int argc, char *argv[]) {

    std::vector<int> vi;
    std::unique_ptr<sf::RenderWindow> upW(new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "OMG!!!"));
    //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "OMG!!!");
    sf::RenderWindow& window = *upW;
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::View view = window.getDefaultView();
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized: {
                    LOGI("[EVT] - resized!!!");
                    view.setSize(event.size.width, event.size.height);
                    view.setCenter(event.size.width / 2, event.size.height / 2);
                    window.setView(view);
                } break;
                case sf::Event::TouchBegan: {
                    LOGI("[EVT] - touch!!!");
                    if (event.touch.finger == 0) {
                        shape.setPosition(event.touch.x, event.touch.y);
                    }
                } break;

                default: break;
            }
        }
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }
    return 0;
}