//
// Created by Dell on 2021/9/30.
//

#ifndef CPP_CNUMBERFACTORY_H
#define CPP_CNUMBERFACTORY_H

#endif //CPP_CNUMBERFACTORY_H
#pragma once
class CNumberFactory
        {
        public:
            virtual void Add(int number) {};
            virtual void Sub(int number) {};
            virtual int GetValue() {return -1;};

            virtual void SetValue(int number) {};
            CNumberFactory *Create();
        };