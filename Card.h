//
// Created by sloopster on 10/11/26.
//

#pragma once
#include <ostream>
#include<string>

class Card {
public:
    Card(const std::string& color, int rank) : color_(color), rank_(rank) {}

    friend std::ostream& operator<<(std::ostream& out, const Card& c) {
        return out << c.color_ << " " << c.rank_;
    }

private:
    std::string color_;
    int rank_;
};
