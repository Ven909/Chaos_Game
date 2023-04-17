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
    font.loadFromFile("KOMIKAP_.ttf");  //change to different font if needed, also put it in a folder called fonts
    promptUser.setFont(font);
    
    RectangleShape rect(Vector2f(2, 2));

    // may wanna use pairs instead?? already included the header btw: #include <utility>
    //don't know if this is how vector 2f is used??
    Vector2f vertexes; //used to store the first 3 clicks which will form teh triangle
    Vector2f points;   //used to store the 4 click
    
    Event event;
    //handling the user input
    while (window.isOpen())
    {
         while(window.pollEvent(event))
         {
             //when the user pushes a button...
             if(event.type == Event::MouseButtonPressed)
             {
                 //if the vertexes vector reaches a size of 4, push the fourth point into the points vector instead to start the game
                 if(vertexes.size() == 4)
                 {
                     points.push_back(event.mouseButton.x, event.mouseButton.y);  // this notation may be off
                 }
                 //otherwise push the 3 points into the vertexes vector
                 else
                 {
                     vertexes.push_back(event.mouseButton.x, event.mouseButton.y);  // this notation may be off
                 }
             }
             // if user closes window or presses esacpe, end the game
             else if((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape))) 
             {
                 window.close();
             }
         }
     }
    //drawing the midpoints to generate the fractal
    int vertexRand = rand() % 3; // choosing random vertex point for the triangle
    int lastPoint = points.size() - 1;  //the index in the points index
    int Mid_x = (points[lastPoint].x + vertexes[vertexRand].x) / 2;   // the x coordinate for the midpoint
    int Mid_y = (points[lastPoint].y + vertices[vertexRand].y) / 2;   // the y coordinate for the midpoint
    
    points.push_back(Mid_x, Mid_y);
    
    //rect.setPosition(Mid_x, Mid_y); // may need this
    
    
    //draw the coordinate points 
    while(window.isOpen())
    {
        //draw triangle
        for (int i = 0; i < vertexes.size(); i++)
        {
            rect.setPosition(vertexes.at(i).x, vertexes.at(i).y);
            window.draw(rect);
        }
        //draw the fractal part
        for (int j = 0; j < points.size(); j++)
        {
            rect.setPosition(points.at(i).x, points.at(i).y);
            window.draw(rect);
        }
    }
    
    //display everything created
    window.draw(promptUser);
    
    window.display();

}
