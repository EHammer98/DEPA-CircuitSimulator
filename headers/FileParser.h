#pragma once

#include <string>

struct nodeData
{
    std::string name;
    std::string type;
    std::vector<std::string> edges;
};


class Node {
public:
    virtual void process() = 0;
};

class InputHighNode : public Node {
public:
    void process() override {
        // Process logic for INPUT_HIGH node
    }
};

class InputLowNode : public Node {
public:
    void process() override {
        // Process logic for INPUT_LOW node
    }
};

class ProbeNode : public Node {
public:
    void process() override {
        // Process logic for PROBE node
    }
};

class OrNode : public Node {
public:
    void process() override {
        // Process logic for OR node
    }
};

class AndNode : public Node {
public:
    void process() override {
        // Process logic for AND node
    }
};

class NotNode : public Node {
public:
    void process() override {
        // Process logic for NOT node
    }
};

class Edge {
public:
    Node* from;
    Node* to;
};



class FileParser
{
public:
    std::vector<nodeData> parse(std::string fileName);
};