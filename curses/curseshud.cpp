#include "curseshud.h"

//CursesHud::CursesHud()
//{

//}

//CursesText::CursesText(File& file) : text_(file.content())
//{
//    set(CursesColorPair::WHITE_BLACK, 0, 0);
//}

//CursesText::CursesText(std::vector<std::string> text) : text_(text)
//{
//    set(CursesColorPair::WHITE_BLACK, 0, 0);
//}

//CursesText::CursesText(CursesText &&cursesText)
//{
//    this->text_ = std::move(cursesText.text_);
//    this->colorPair_ = cursesText.colorPair_;
//    this->x_ = cursesText.x_;
//    this->y_ = cursesText.y_;
//}

//void CursesText::set(CursesColorPair colorPair, int x, int y)
//{
//    std::lock_guard<std::mutex> lock(objectMutex);
//    colorPair_ = colorPair;
//    x_ = x;
//    y_ = y;
//}

//void CursesText::print()
//{
//    std::lock_guard<std::mutex> lock(objectMutex);
//    for (int i = 0; i < text_.size(); i++)
//    {
//        move(x_ + i, y_);
//        attron(COLOR_PAIR(colorPair_));
//        printw(text_[i].data());
//    }
//    refresh();
//}

//void CursesText::moveTo(int x, int y)
//{
//    std::lock_guard<std::mutex> lock(objectMutex);
//    x_ = x;
//    y_ = y;
//}

//void CursesText::update(std::vector<std::string> text)
//{
//    std::lock_guard<std::mutex> lock(objectMutex);
//    text_ = text;
//}

//void CursesText::setColorPair(CursesColorPair colorPair)
//{
//    std::lock_guard<std::mutex> lock(objectMutex);
//    colorPair_ = colorPair;
//}
