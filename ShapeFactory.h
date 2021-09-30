//
// Created by Dell on 2021/9/29.
//

#ifndef CPP_SHAPEFACTORY_H
#define CPP_SHAPEFACTORY_H

#endif //CPP_SHAPEFACTORY_H
#pragma once

class ShapeFactory
        {
        public:
            ShapeFactory(){};
            virtual ~ShapeFactory(){};

            virtual float Circumstance(){return 0;};
            ShapeFactory *Create(float a,float b,float c);
            ShapeFactory *Create(float a,float b,float c,float d);
            ShapeFactory *Create(float r);
        };