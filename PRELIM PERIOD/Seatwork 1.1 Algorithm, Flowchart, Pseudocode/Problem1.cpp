#include <iostream>

int main(){

    float quiz1, quiz2, quiz3, TotalScores, grades, MaxScore, Percentage, Percent;
    std::string name;

//the system asks for the student name and the scores in each quiz using user input
    std::cout << "Welcome to the student quiz calculator.\n";
    std::cout << "Enter the student name: ";
    std::cin >> name;
    std::cout << "Input the student grade for quiz 1: ";
    std::cin >> quiz1;
    std::cout << "Input the student grade for quiz 2: ";
    std::cin >> quiz2;
    std::cout << "Input the student grade for quiz 3: ";
    std::cin >> quiz3;
    std::cout << "Input the highest possible total score: ";
    std::cin >> MaxScore;

    TotalScores = quiz1 + quiz2 + quiz3;
    grades = TotalScores / 3;
    Percent = TotalScores / MaxScore;
    Percentage = Percent * 100;
    
    std::cout << "Scores of " << name << ": " << quiz1 << ", " << quiz2 << ", " << quiz3 << "\n";
    std::cout << "Total Score: " << TotalScores << "/" << MaxScore << "\n";
    std::cout << "Average Quiz Score: " << grades << "\n";
    std::cout << "Percentage: " << Percentage << "%";

    return 0;
}
