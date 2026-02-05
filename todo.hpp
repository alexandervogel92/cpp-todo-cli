#pragma once
#include <vector>
#include <string>

struct Todo {
    std::string text;
    bool done = false;
};

class TodoList {
    public:
        void add(const std::string& text);
        void list() const;

    private:
        std::vector<Todo> tasks;
};
