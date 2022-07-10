#include "AutoMacro/Core/Command/CommandFactory.h"

#include <memory>

namespace AutoMacro {
namespace {
template<class T>
class TCommandAdapter : public Command {
 public:
    explicit TCommandAdapter(std::shared_ptr<TCommand<T>> command)
        : command_(command) {
    }

    void execute() final {
        command_->execute();
    }

 private:
     std::shared_ptr<TCommand<T>> command_;
};
}  // namespace

template<>
DLL_EXPORTS std::shared_ptr<Command> createCommand(
        std::shared_ptr<TCommand<void>> command) {
    return std::make_shared<TCommandAdapter<void>>(command);
}

template<>
DLL_EXPORTS std::shared_ptr<Command> createCommand(
        std::shared_ptr<TCommand<bool>> command) {
    return std::make_shared<TCommandAdapter<bool>>(command);
}
}  // namespace AutoMacro
