// Copyright 2020 Malenko Artem artem.malenko@yandex.ru

#include <gtest/gtest.h>

#include <string>

#include "header.hpp"

TEST(Stack, empty) {
    Stack<int> stack;
    EXPECT_EQ(stack.empty(), true);

    stack.push(10);
    EXPECT_EQ(stack.empty(), false);
}

TEST(Stack, size) {
    Stack<int> stack;
    EXPECT_EQ(stack.size(), 0);

    stack.push(2);
    EXPECT_EQ(stack.size(), 1);

    stack.push(1);
    EXPECT_EQ(stack.size(), 2);

    stack.push(3);
    EXPECT_EQ(stack.size(), 3);

    stack.pop();
    EXPECT_EQ(stack.size(), 2);

    stack.pop();
    EXPECT_EQ(stack.size(), 1);

    stack.pop();
    EXPECT_EQ(stack.size(), 0);
}

TEST(Stack, push) {
    Stack<int> stack;
    EXPECT_EQ(stack.size(), 0);

    const int x = 20;  // for void push(const T& value);
    stack.push(x);
    EXPECT_EQ(stack.size(), 1);

    stack.push(-3);
    EXPECT_EQ(stack.size(), 2);

    stack.push(0);
    EXPECT_EQ(stack.size(), 3);
}

TEST(Stack, pop) {
    Stack<int> stack;
    stack.push(121);
    stack.push(-7);
    stack.push(0);

    EXPECT_EQ(stack.size(), 3);

    stack.pop();
    EXPECT_EQ(stack.size(), 2);

    stack.pop();
    EXPECT_EQ(stack.size(), 1);

    stack.pop();
    EXPECT_EQ(stack.size(), 0);
}

TEST(Stack, head) {
    Stack<int> stack;

    stack.push(110);
    EXPECT_EQ(stack.head(), 110);

    stack.push(100);
    EXPECT_EQ(stack.head(), 100);

    stack.pop();
    EXPECT_EQ(stack.head(), 110);
}

TEST(Stack, push_emplace) {
    Stack<std::string> stack;

    stack.push_emplace("10");
    EXPECT_EQ(stack.head(), "10");

    stack.push_emplace("2");
    EXPECT_EQ(stack.head(), "2");

    stack.push_emplace("45");
    EXPECT_EQ(stack.head(), "45");
}