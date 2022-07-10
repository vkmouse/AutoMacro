#pragma once
#include <string>
#include <vector>

#include "AutoMacro/Util/Util.h"
#include "AutoMacro/Cv/Cv.h"

namespace AutoMacro {
namespace CommandTest {
Kvm getKvm(Histories* histories);
Kvm getKvm(Histories* histories, std::vector<std::string> filenames);

template<class T>
void execute(Histories* histories, T parameter) {
    auto cmd = Factory::createCommand(&parameter);
    histories->clear();
    histories->record("---");
    cmd->execute();
    histories->record("---");
}

template<class T>
void execute(Histories* histories, T parameter1, T parameter2) {
    auto cmd1 = Factory::createCommand(&parameter1);
    auto cmd2 = Factory::createCommand(&parameter2);
    histories->clear();
    histories->record("---");
    cmd1->execute();
    histories->record("---");
    cmd2->execute();
    histories->record("---");
}

template<class T>
void execute(Histories* histories, T parameter1, T parameter2, T parameter3) {
    auto cmd1 = Factory::createCommand(&parameter1);
    auto cmd2 = Factory::createCommand(&parameter2);
    auto cmd3 = Factory::createCommand(&parameter3);
    histories->clear();
    histories->record("---");
    cmd1->execute();
    histories->record("---");
    cmd2->execute();
    histories->record("---");
    cmd3->execute();
    histories->record("---");
}
}  // namespace CommandTest
}  // namespace AutoMacro
