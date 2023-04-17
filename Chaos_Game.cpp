#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    //Creates a video mode object
    VideoMode vm(1920, 1080);
    //Creates an open window
    RenderWindow window(vm, "Chaos Game", Style::Default);
    
    //telling the user how to use the program 
    Text promptUser;
    promptUser.setString(" Welcome to the Chaos Game! " 
                         "Click 4 times using your mouse. The first 3 clicks will be used to make a triangle and the fourth click will start the game.");
    promptUser.setCharacterSize(18);  //setting font size
    promptUser.setFillColor(Color::Red);   //setting font color
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");  //change to different font if needed, also put it in a folder called fonts
    promptUser.setFont(font);
    
    RectangleShape rectangle(Vector2f(2, 2));

    // may wanna use pairs instead?? already included the header btw: #include <utility>
    vector<Vector2f> vertexes; //used to store the first 3 clicks which will form teh triangle
    vector<Vector2f> points;   //used to store the 4 click
    
    Event event;
}
