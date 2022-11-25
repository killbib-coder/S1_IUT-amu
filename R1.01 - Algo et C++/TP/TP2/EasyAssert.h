/**
*
* @file    IziAssert.h
*
* @authors Floran NARENJI-SHESHKALANI, Alain Casali
*
* @version V1.0
* @date    24/11/2014
*
* @version V1.1
* @date     1/10/2016
* @brief    maj
*
* @brief  IZI_ASSERT
*
**/
#pragma once

#include <iostream>

#define EASY_ASSERT(condition) EasyAssert(condition, #condition, __FILE__, __LINE__, __func__);

namespace {
    bool EasyAssert(bool success, const char* condition, const char* fileName, const int lineNumber, const char* functionName)
    {
        std::cout << (success ? "\033[32mASSERTION SUCCESS: \n" : "\033[31mASSERTION FAILED: \n")
                << "\tFunction: "
                << functionName
                << "\n\tCondition: "
                << condition
                << "\n\tFile: "
                << fileName
                << "\n\tLine: "
                << std::to_string(lineNumber)
                << "\n\033[0m"
                << std::endl;
            return true;
    }//EasyAssert ()
}
