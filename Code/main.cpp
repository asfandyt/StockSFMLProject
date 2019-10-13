//
//  main.cpp
//  COMP4300_A1
//
//  Created by Asfand Tareen on 2019-09-16.
//  Copyright © 2019 Asfand Tareen. All rights reserved.
//
/*
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
*/
 

#include <SFML/Graphics.hpp> // TODO: include <sfml-graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

int main(int argc, char * argv[])
{
    // Creating ifstream object, to read from file
    std::ifstream source;
    
    // Object to store the file contents
    // Storing words as string type in a vector data structure
    std::vector<std::string> Words;
    
    
    // TODO: Store different child shapes under base shape
    // Add shapes to RectangleShape class
    // RectangleShape class is a subclass of Shape class in SFML
    std::vector<sf::RectangleShape> rectangles;
    // CircleShape subclass of Shape class
    std::vector<sf::CircleShape> circles;
    
    // Created vector containing shared_ptr to contain references to shapes
    // We will use '->' to add/change members
    std::vector<std::shared_ptr<sf::Shape>> shapes;
    
    
    // TODO:
    std::vector<sf::Vector2f> velocity;
    
    
    // Window variables
    int wWidth = 0, wHeight = 0;
    // Font variables
    int fontSize = 0, fontColorR = 0, fontColorG = 0, fontColorB = 0;
    
    // Shape properties
    float shapeX, shapeY, shapeWidth, shapeHeight, shapeRadius, shapeVX = 0.0f, shapeVY = 0.0f;
    int shapeColorRed, shapeColorGreen, shapeColorBlue;
    std::string shapeName;
    
    // TODO: Font file path
    std::string fontFilePath = "";
    
    // Configuration file
    source.open("config.txt");
    
    // Error handling
    if (!source)
    {
        std::cout << "File not found!" << std::endl;
        exit(-1);
    }
    
    // Variable to catch words
    std::string word;
    
    // Loop control variable for Window and Font
    int loopCtrlWF = 0;
    
    // Add all words on file into vector
    // Irrelevant to requirements, for understanding only
    while (source >> word)
    {
        // Testing and Storing
        // std::cout << "Loop: " << loopCtrlWF << ", Line 62: " << word << std::endl;
        Words.push_back(word);
        loopCtrlWF++;
        
    }
    
    // Getting the total words
    long vectorSize = Words.size();
    
    try {
        
        for (int j = 0; j < vectorSize; j++) {
            
            // std::cout << "Testing for loop: " << Words[j] << std::endl;
            
            // Initiate Window properties
            if (Words[j] == "Window")
            {
                // Number of parameter
                int numParamsWin = 2;
                
                for (int i = j + 1; i < numParamsWin; i++) {
                    
                    // stoi get values out of a string literal
                    wWidth = std::stoi(Words[i]);
                    wHeight = std::stoi(Words[i + 1]);
                }
                
            }
            else if (Words[j] == "Font")
            {
                // Number of parameter
                // int numParamsFont = 5;
                
                fontFilePath = Words[j + 1];
                fontSize = std::stoi(Words[j + 2]);     // stoi get values out of a string literal
                fontColorR = std::stoi(Words[j + 3]);
                fontColorG = std::stoi(Words[j + 4]);
                fontColorB = std::stoi(Words[j + 5]);
                            }
            else if (Words[j] == "Circle")
            {
                shapeName = Words[j + 1];
                shapeX = std::stoi(Words[j + 2]);
                shapeY = std::stoi(Words[j + 3]);
                shapeVX = std::stof(Words[j + 4]);
                shapeVY = std::stof(Words[j + 5]);
                shapeColorRed = std::stoi(Words[j + 6]);
                shapeColorGreen = std::stoi(Words[j + 7]);
                shapeColorBlue = std::stoi(Words[j + 8]);
                shapeRadius = std::stoi(Words[j + 9]);
                
                /*
                auto circle = sf::CircleShape(shapeRadius);
                circle.setFillColor(sf::Color(shapeColorRed, shapeColorGreen, shapeColorBlue));
                circle.setPosition(shapeX, shapeY);
                circles.push_back(circle);
                 */
                
                // Update shape via references
                auto shape = std::make_shared<sf::CircleShape>(sf::CircleShape(shapeRadius));
                
                shape -> setFillColor(sf::Color(shapeColorRed, shapeColorGreen, shapeColorBlue));
                shape -> setPosition(shapeX, shapeY);
                shapes.push_back(shape);
                
                velocity.push_back(sf::Vector2f(shapeVX, shapeVY));
            }
        
            else if (Words[j] == "Rectangle")
            {
                // Created Rectangle successfully
                shapeName = Words[j + 1];
                shapeX = std::stoi(Words[j + 2]);
                shapeY = std::stoi(Words[j + 3]);
                shapeVX = std::stof(Words[j + 4]);
                shapeVY = std::stof(Words[j + 5]);
                shapeColorRed = std::stoi(Words[j + 6]);
                shapeColorGreen = std::stoi(Words[j + 7]);
                shapeColorBlue = std::stoi(Words[j + 8]);
                shapeWidth = std::stoi(Words[j + 9]);
                shapeHeight = std::stoi(Words[j + 10]);
                
                /*
                auto rectangle = sf::RectangleShape(sf::Vector2f(shapeWidth, shapeHeight));
                rectangle.setFillColor(sf::Color(shapeColorRed, shapeColorGreen, shapeColorBlue));
                rectangle.setPosition(shapeX, shapeY);
                rectangles.push_back(rectangle);            }
                 */
                auto shape = std::make_shared<sf::RectangleShape>(sf::RectangleShape(sf::Vector2f(shapeX, shapeY)));
                
                shape -> setFillColor(sf::Color(shapeColorRed, shapeColorGreen, shapeColorBlue));
                shape -> setPosition(shapeX, shapeY);
                shapes.push_back(shape);
                
                velocity.push_back(sf::Vector2f(shapeVX, shapeVY));
            }
            
        }
    }
    catch(const char* msg)
    {
        std::cout << msg << std::endl;
    }
    
    // NOTE: The above code works
    
    // The window object we will be manipulating
    // sf:: is the namespace of SFML
    // RenderWindow is the class we use to render the window
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
    
    // Render the shapes
    long numOfCircles = circles.size();
    long numOfRectangles = rectangles.size();
    
    // Main loop
    while (window.isOpen())
    {
        // Event handling
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            // Handle window closure
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            
            // this event is triggered when a key is pressed
            if (event.type == sf::Event::KeyPressed)
            {
                // print the key that was pressed to the console
                std::cout << "Key pressed with code = " << event.key.code << "\n";
                
                // example, what happens when x is pressed
                if (event.key.code == sf::Keyboard::X)
                {
                    // reverse the direction of the circle on the screen
                    shapeVX *= -1.0f;
                    shapeVY *= -1.0f;
                    
                }
            }
            
        }
        
        window.clear();
        
        // New loop to render the objects
        for (std::size_t i = 0; i < shapes.size(); i++) {
            
            // Move the objects
            shapes[i] -> setPosition(shapes[i] -> getPosition().x - velocity[i].x, shapes[i] -> getPosition().y - velocity[i].y);
            
            // draw object onto window object
            window.draw(*shapes[i]);
            
        }
        
        for (std::size_t k = 0; k < numOfCircles; k++)
        {
            /*
                TODO:: Find the left-top point of object: bounding box
                Add the left point to the width of the object.
                There are two places the object to wall intersection is possible
                the left side or the right side. So, track two locations.
                Calculate the left bound point: circles[k].getLocalBounds
            */
            float xLeftBB, yTopBB;
            float currentLocationX, currentLocationY;
            
            xLeftBB = circles[k].getGlobalBounds().left;
            yTopBB = circles[k].getGlobalBounds().top;
            
            // For negative speed we will be checking intersection
            // of the top and left walls
            if(shapeVX > 0.0f)
            {
                // when moving left, compare left wall
                currentLocationX = xLeftBB;
                
                if(currentLocationX <= 0.0f)
                    shapeVX *= -1.0f;
            }
            else
            {
                // when moving right, compare right wall
                currentLocationX = xLeftBB + 2 * (circles[k].getRadius());
                
                if(currentLocationX >= wWidth)
                    shapeVX *= -1.0f;
            }
            
            if(shapeVY > 0.0f)
            {
                // when moving up, compare upper wall
                currentLocationY = yTopBB;
                
                if(currentLocationY <= 0.0f)
                    shapeVY *= -1.0f;
            }
            else
            {
                // when moving down, compare lower wall
                currentLocationY = yTopBB + 2 * (circles[k].getRadius());
                
                if(currentLocationY >= wHeight)
                    shapeVY *= -1.0f;
            }
            
            // Animate object
            circles[k].setPosition(circles[k].getPosition().x - shapeVX, circles[k].getPosition().y - shapeVY);
            
            window.draw(circles[k]);
        }
        
        for (int l = 0; l < numOfRectangles; l++)
        {
            // Animate object
            rectangles[l].setPosition(circles[l].getPosition().x - shapeVX, rectangles[l].getPosition().y - shapeVY);
            
            
            window.draw(rectangles[l]);
        }
        
        // window.draw(circle);    // Draw the object
        // window.draw(text);      // draw the text
        window.display();          // call the window display function
    }
    
    // Variables needed for the Window and Font is complete
    
    std::cout << "Window Width: " << wWidth << std::endl;
    std::cout << "Window Height: " << wHeight << std::endl;
    std::cout << "Font File: " << fontFilePath << std::endl;
    std::cout << "Font Size: " << fontSize << std::endl;
    std::cout << "Font Color Red: " << fontColorR << std::endl;
    std::cout << "Font Color Green: " << fontColorG << std::endl;
    std::cout << "Font Color Blue: " << fontColorB << std::endl;
    
    
    
    // ------------------------------------------------------------------------
    /*
    // create a new window of size 400 by 400 pixels
    // top-left of the window is (0,0) and bottom-right is (w,h)
    const int wWidth = 640;
    const int wHeight = 480;
    
    // The window object we will be manipulating
    // sf:: is the namespace of SFML
    // RenderWindow is the class we use to render the window
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
    
    // let's make a shape that we will draw to the screen
    sf::CircleShape circle(50);             // create a circle shape with radius 50
    circle.setFillColor(sf::Color::Green);  // set the circle color to green
    circle.setPosition(300.0f, 300.0f);     // set the top-left position of the circle
    float circleMoveSpeed = 0.01f;          // we will use this to move the circle later
    
    // let's load a font so we can display some text
    sf::Font arial;
    
    // attempt to load the font from a file
    // TODO: Change to "fonts/arial.ttf"
    if (!arial.loadFromFile("/Users/asfand/Google Drive/MUN/Fall 2019/4300/CodeEnvironment/Platforms/Mac/COMP4300_A1/fonts/arial.ttf"))
    {
        // if we can't load the font, print an error to the error console and exit
        std::cerr << "Could not load font!\n";
        exit(-1);
    }
    
    // set up the text object that will be drawn to the screen
    sf::Text text("Sample Text", arial, 24);
    
    // position the top-left corner of the text so that the text aligns on the bottom
    // text character size is in pixels, so move the text up  from the bottom by its height
    text.setPosition(0, wHeight - (float)text.getCharacterSize());
    
    // main loop - continues for each frame while window is open
    while (window.isOpen())
    {
        // event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            // this event triggers when the window is closed
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            
            // this event is triggered when a key is pressed
            if (event.type == sf::Event::KeyPressed)
            {
                // print the key that was pressed to the console
                std::cout << "Key pressed with code = " << event.key.code << "\n";
                
                // example, what happens when x is pressed
                if (event.key.code == sf::Keyboard::X)
                {
                    // reverse the direction of the circle on the screen
                    circleMoveSpeed *= -1.0f;
                }
            }
        }
        
        // basic animation - move the each frame if it's still in frame
        circle.setPosition(circle.getPosition().x - circleMoveSpeed, circle.getPosition().y - circleMoveSpeed);
        
        // basic rendering function calls
        window.clear();         // clear the window of anything previously drawn
        window.draw(circle);    // draw the circle
        window.draw(text);      // draw the text
        window.display();       // call the window display function
    }
    */
    
    return 0;
}
