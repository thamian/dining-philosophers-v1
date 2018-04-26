#include "philosopherstatus.h"

PhilosopherStatus::PhilosopherStatus(CursesText& philosopher, CursesText& hud, CursesProgressBar& progressBar) : philosopher_(philosopher), hud_(hud), progressBar_(progressBar)
{

}

void PhilosopherStatus::update()
{
    if (action_->name() == "eat")
    {
        philosopher_.setColorPair(CursesColorPair::YELLOW_BLACK);
        progressBar_.updateProgress(progress_, CursesColorPair::BLACK_YELLOW);
    }
    else if (action_->name() == "think")
    {
        philosopher_.setColorPair(CursesColorPair::CYAN_BLACK);
        progressBar_.updateProgress(progress_, CursesColorPair::BLACK_CYAN);
    }
    else if (action_->name() == "wait")
    {
        philosopher_.setColorPair(CursesColorPair::WHITE_BLACK);
        progressBar_.updateProgress(progress_, CursesColorPair::BLACK_WHITE);
    }
    hud_.update(generateHud());
}

void PhilosopherStatus::updateAction(Action& action, int progress)
{
    action_ = &action;
    progress_ = progress;
}

void PhilosopherStatus::setName(std::string name)
{
    philosopherName_ = name;
}

std::vector<std::string> PhilosopherStatus::generateHud()
{
    std::vector<std::string> text;
    int size = philosopherName_.size();
    std::string spaces = "";
    for (int i = 0; i < 11 - size; i++)
    {
        spaces += " ";
    }
    text.push_back(" " + philosopherName_ + spaces);
    text.push_back("            ");
    if (action_->name() == "eat")
    {
        text.push_back(" eating     ");
    }
    else if (action_->name() == "think")
    {
        text.push_back(" thinking   ");
    }
    else if (action_->name() == "wait")
    {
        text.push_back(" waiting    ");
    }
    text.push_back("            ");
    text.push_back("            ");

    return text;
}
