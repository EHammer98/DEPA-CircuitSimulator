#pragma once

#include <string>



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

enum class NodeType { INPUT_HIGH, INPUT_LOW, PROBE, OR, AND, NOT };


class NodeFactory {
public:
    static Node* createNode(NodeType type) {
        switch (type) {
        case NodeType::INPUT_HIGH: return new InputHighNode();
        case NodeType::INPUT_LOW: return new InputLowNode();
        case NodeType::PROBE: return new ProbeNode();
        case NodeType::OR: return new OrNode();
        case NodeType::AND: return new AndNode();
        case NodeType::NOT: return new NotNode();
        default: return nullptr;
        }
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
    void parse(std::string fileName);
};