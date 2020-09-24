//
//  test_constructor.cpp
//  TestAny
//
//  Created by delims on 2020/9/12.
//  Copyright © 2020 delims. All rights reserved.
//

#include "test_constructor.hpp"

class animal
{
    
private:
    int weight;
    int height;
    int color;
public:
//    animal(int height = 10,int color = 11):height(height)
//    {
//
//    }
    
    int getHeight()
    {
        return this->height;
    }
    

//    animal(){};
};

class dog:private animal
{
public:
    int animal2;
    dog(int height):animal2(12)
    {
        printf("%d \n",this->getHeight());
        printf("%d \n",this->animal2);
    }
//    dog(){};
    
};

void test_constructor()
{
    
    dog d(4152);
    
//    printf("%d \n",d.getHeight());
}
