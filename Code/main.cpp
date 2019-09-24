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

int main(int argc, char * argv[])
{
    // Creating ifstream object
    std::ifstream source;
    
    // Object to store the file contents
    std::vector<std::string> Words;
    
    // Window variables
    int wWidth = 0, wHeight = 0;
    // Font variables
    int fontSize = 0, fontColorR = 0, fontColorG = 0, fontColorB = 0;
    
    // Font file path
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
    while (source >> word)
    {
        // Testing and Storing
        std::cout << "Loop: " << loopCtrlWF << ", Line 62: " << word << std::endl;
        Words.push_back(word);
        loopCtrlWF++;
        
    }
    
    
    for (std::string  item : Words) {
        std::cout << "Testing for loop: " << item << std::endl;
        
        if (item == "Window")
        {
            // Initiate Window properties
        }
        else if (item == "Font")
        {
            
        }
        else if (item == "Circle")
        {
            
        }
    
        else if (item == "Rectangle")
        {
            
        }
        
        
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
