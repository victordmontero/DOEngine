/*
 * ============================================================================
 * DOEngine
 * Copyright (c) 2026 Victor D. Montero, Aneury Perez
 * All Rights Reserved.
 *
 * Licensed under the MIT License.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * 1. The above copyright notice, this license notice, and this disclaimer
 *    MUST be included in all copies or substantial portions of the Software.
 *
 * 2. This notice may not be removed from the original source files distributed
 *    as part of this project.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * ============================================================================
 */

#include "StringUtils.h"

namespace doengine
{

void readMapFile(const char* filename, std::vector<std::string>& ret)
{
    std::fstream file(filename, std::ios::in);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            ret.emplace_back(line);
            line = "";
        }
    }
}

std::vector<std::string> splitString(const std::string& original, char ch)
{
    std::vector<std::string> ret;
    std::string testEmplace;
    for (auto it : original)
    {
        if (it == ch)
        {
            if (testEmplace.size() > 0)
            {
                ret.emplace_back(testEmplace);
                testEmplace = "";
            }
        }
        else
        {
            testEmplace += it;
        }
    }
    if (testEmplace.size() > 0)
    {
        ret.emplace_back(testEmplace);
    }
    return ret;
}
std::vector<char> splitChar(const std::string& original,
                            const std::string& ignoredChars)
{
    std::vector<char> ret;
    for (auto it : original)
    {
        if (ignoredChars.find(it) == std::string::npos)
        {
            ret.emplace_back(it);
        }
    }
    return ret;
}

std::string vectorOfCharToString(const std::vector<char>& chars)
{
    std::string str;
    for (auto it : chars)
    {
        SDL_Log("%c", it);
        str += it;
    }
    return str;
}

int StringAsInt(const std::string& str)
{
    return std::stoi(str);
}

bool isCharInGroup(char ch, const std::string group)
{
    return (group.find(ch,0) != std::string::npos);
}

}; // namespace doengine