#ifndef COMMAND_H
#define COMMAND_H

class Command {
    public:
        virtual void execute() = 0; // Pure virtual function to execute the command
        virtual void undo()    = 0;
        virtual void getName() const = 0;

        virtual ~Command() = default;
};

#endif // COMMAND_H