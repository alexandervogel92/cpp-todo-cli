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
    bool toggleDone(size_t index1based);
    bool loadFromFile(const std::string& path);
    bool saveToFile(const std::string& path) const;

private:
    std::vector<Todo> tasks;
};
