#include <SFML/Graphics.hpp>
#include <iostream>  // 添加这一行
int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML Example");

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        // 如果加载字体失败，输出错误信息并退出
        std::cerr << "Failed to load font file!" << std::endl;
        return 1;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // 设置要显示的数字
        int number = 666;
        text.setString(std::to_string(number));

        // 居中显示文本
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.width / 2, textBounds.height / 2);
        text.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

        window.draw(text);
        window.display();
    }

    return 0;
}