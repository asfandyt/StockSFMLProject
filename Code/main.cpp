//  Created by Asfand Tareen on 2019-09-16.
//  Copyright © 2019 Asfand Tareen. All rights reserved.
//
 

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
    
    
    // Created vector containing shared_ptr to contain references to shapes
    // We will use '->' to add/change members
    std::vector<std::shared_ptr<sf::Shape>> shapes;
    
    // Store and track velocities
    std::vector<sf::Vector2f> velocity;
    
    // Track shape names
    std::vector<std::string> names;
    
    // Track Text pointers
    std::vector<std::shared_ptr<sf::Text>> texts;
    
    // Default font
    sf::Font font;
    
    // Window variables
    int wWidth = 0, wHeight = 0;
    // Font variables
    int fontSize = 0, fontColorR = 0, fontColorG = 0, fontColorB = 0;
    
    // Shape properties
    float shapeX, shapeY, shapeWidth, shapeHeight, shapeRadius, shapeVX = 0.0f, shapeVY = 0.0f;
    int shapeColorRed, shapeColorGreen, shapeColorBlue;
    std::string shapeName;
    
    // TODO: Font file path
    std::string fontFilePath = "arial.ttf";
    
    // Load font from path
    if (!font.loadFromFile(fontFilePath)) {
        std::cout << "Error: Font file not found" << std::endl;
    }
    
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
                
                // Update shape via references
                auto shape = std::make_shared<sf::CircleShape>(sf::CircleShape(shapeRadius));
                
                shape -> setFillColor(sf::Color(shapeColorRed, shapeColorGreen, shapeColorBlue));
                shape -> setPosition(shapeX, shapeY);
                shapes.push_back(shape);
                
                velocity.push_back(sf::Vector2f(shapeVX, shapeVY));
                
                auto text = std::make_shared<sf::Text>(sf::Text(Words[j], font, 24));
                texts.push_back(text);
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
                
                auto shape = std::make_shared<sf::RectangleShape>(sf::RectangleShape(sf::Vector2f(shapeX, shapeY)));
                
                shape -> setFillColor(sf::Color(shapeColorRed, shapeColorGreen, shapeColorBlue));
                shape -> setPosition(shapeX, shapeY);
                shapes.push_back(shape);
                
                velocity.push_back(sf::Vector2f(shapeVX, shapeVY));
                
                auto text = std::make_shared<sf::Text>(sf::Text(Words[j], font, 24));
                texts.push_back(text);
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
                    for (std::size_t i = 0; i < velocity.size(); i++)
                    {
                        velocity[i] *= -1.0f;
                    }
                    
                }
            }
            
        }
        
        window.clear();
        
        // New loop to render the objects
        for (std::size_t i = 0; i < shapes.size(); i++) {
            
            float xLeftBB, yTopBB, shapeWidth, shapeHeight, radius;
            float currentLocationX, currentLocationY, textX, textY;
            
            xLeftBB = shapes[i] -> getGlobalBounds().left;
            yTopBB = shapes[i] -> getGlobalBounds().top;
            
            
            std::string circleShape = "CircleShape";
            std::string shapeName = typeid(*shapes[i]).name();
            
            // In case circle, the width is 2X the radius
            if (shapeName.find(circleShape) != std::string::npos)
            {
                sf::CircleShape* c = dynamic_cast<sf::CircleShape*>(shapes[i].get());
                radius = c -> getRadius();
                
                // Text
                textX = shapes[i] -> getPosition().x  + radius - texts[i] -> getLocalBounds().width / 2;
                textY = shapes[i] -> getPosition().y + radius - texts[i] -> getLocalBounds().height / 2;
                
            }
            else
            {
                sf::RectangleShape* r = dynamic_cast<sf::RectangleShape*>(shapes[i].get());
                // when moving right, compare right wall
                shapeWidth = r -> getPoint(0).x;
                shapeHeight = r -> getPoint(0).y;
                
                // Text
                textX = shapes[i] -> getPosition().x + (shapes[i] -> getLocalBounds().width / 2) - texts[i] -> getLocalBounds().width / 2;
                textY = shapes[i] -> getPosition().y + (shapes[i] -> getLocalBounds().height / 2) - texts[i] -> getLocalBounds().height / 2;
                
            }
            
            if(velocity[i].x > 0.0f)
            {
                // when moving left, compare left wall
                currentLocationX = xLeftBB;
                
                if(currentLocationX <= 0.0f)
                    velocity[i].x *= -1.0f;
            }
            else
            {
                // In case circle, the width is 2X the radius
                if (shapeName.find(circleShape) != std::string::npos)
                {
                    currentLocationX = xLeftBB + 2 * radius;
                    
                }
                else
                {
                    // TODO: Width not correct
                    // currentLocationX = xLeftBB + shapeWidth;
                    currentLocationX = shapes[i] -> getPosition().x + shapes[i] -> getLocalBounds().width;
                    
                }
                
                
                if(currentLocationX >= wWidth)
                    velocity[i].x *= -1.0f;
            }
            
            if(velocity[i].y > 0.0f)
            {
                // when moving up, compare upper wall
                currentLocationY = yTopBB;
                
                if(currentLocationY <= 0.0f)
                    velocity[i].y *= -1.0f;
            }
            else
            {
                // In case circle, the width is 2X the radius
                if (shapeName.find(circleShape) != std::string::npos)
                {
                    currentLocationY = yTopBB + 2 * radius;
                    
                }
                else
                {
                    //currentLocationY = yTopBB + shapeHeight;
                    currentLocationY = shapes[i] -> getPosition().y + shapes[i] -> getLocalBounds().height;
                    
                }
                
                if(currentLocationY >= wHeight)
                    velocity[i].y *= -1.0f;
            }
            // Move the objects and text
            shapes[i] -> setPosition(shapes[i] -> getPosition().x - velocity[i].x, shapes[i] -> getPosition().y - velocity[i].y);
            
            texts[i] -> setPosition(textX, textY);
            // draw object and text onto window object
            window.draw(*shapes[i]);
            window.draw(*texts[i]);
            
        }
        
        
        window.display();
    }
    
    
    return 0;
}
