#!/usr/bin/env bash

g++ src/main.cpp \
    src/view/View.cpp \
    src/view/Hand.cpp \
    src/view/Image.cpp \
    src/KeyEventPublisher.cpp \
    -I/home/nicklas/src/cardgames/blackjack/src/view/ \
    -std=c++20 \
    -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -ljsoncpp
